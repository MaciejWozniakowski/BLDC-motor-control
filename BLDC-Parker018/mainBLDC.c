


#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "funkcje.h"
#include "stale.h"

#define __BSD_VISIBLE
#include "math.h"

//nastawy regularorow
#define TS 0.0001
#define tau  0.5
#define min_vel  -2
#define max_vel  10
#define min_i  -60
#define max_i  60
#define kr_vel  20
#define ki_vel  26
#define ki_i  10
#define kp_i  40
#define rpm 10
//-----------------------------------

//nasze includy
#include "mcd.h"
#include "abcdq.h"
#include "dqabc.h"
#include "derivative.h"
#include "PI.h"

//nasze struktury
struct mc_donaldy mak;
struct dq_abc trans_dq_abc;
struct abc_dq trans_abc_dq;

struct PI PI_reg_iq;
struct PI PI_reg_id;
struct PI PI_reg_vel;

struct derivative drv;


// Prototype statements for functions found within this file.
__interrupt void adc_isr(void);

int praca =1;  //0-STOP NAPED; 1-ZEZWOLENIE NA PRACE

float d1=0.5;
float d2= -0.4;
float d3= -0.4;
float graphiA[200], graphiB[200], graphiC[200];
int temp = 0;

float iB=0.0;
float iC=0.0;

float PhiMech=0.0;
float magneticPoles = 4;
//nasze kody

float alfa = 0, a = 0, b = 0, c = 0;
//float d = 1.15, q = 0;
float InvUdc = 2*0.01428571;

float omega_fake=1;


unsigned long long int AdcIntCounter=0;

void main(void){
   // Step 1. Initialize System Control:
   InitSysCtrl();
   // Step 2. Initialize GPIO:
   InitPWMGpio();
   EPwm_Control123(0);
   InitEncGpio();
   derivative_init(&drv, TS);
   PIInit(&PI_reg_iq, TS, kp_i, ki_i, max_i, min_i);
   PIInit(&PI_reg_id, TS, kp_i, ki_i, max_i, min_i);
   PIInit(&PI_reg_vel, TS, kr_vel, ki_vel, max_vel, min_vel);


   // Step 3. Clear all interrupts and initialize PIE vector table:
   // Disable CPU interrupts
   DINT;

   // Initialize the PIE control registers to their default state.
   InitPieCtrl();

   // Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

   // Initialize the PIE vector table with pointers to the shell Interrupt
   // Service Routines (ISR).
   InitPieVectTable();

   // Interrupts that are used in this example are re-mapped to
   EALLOW;  // This is needed to write to EALLOW protected register
   PieVectTable.ADCINT1 = &adc_isr;
   EDIS;    // This is needed to disable write to EALLOW protected registers

   // Step 4. Initialize all the Device Peripherals:
   InitAdc();  // For this example, init the ADC
   AdcOffsetSelfCal();

   // Step 5. User specific code, enable interrupts:
   PieCtrlRegs.PIEIER1.bit.INTx1 = 1;   // Enable INT 1.1 in the PIE
   IER |= M_INT1;                       // Enable CPU Interrupt 1
   EINT;                                // Enable Global interrupt INTM
   ERTM;                                // Enable Global realtime interrupt DBGM

   InitADCConv();
   InitPWM();
   // Wait for ADC interrupt
   while(1){
	   __asm(" NOP");
   }

}

__interrupt void  adc_isr(void)
{
	EPwm_Control123(praca);

	iB = AdcResult.ADCRESULT0 * (-0.008684) + 23.339994;
	iC = AdcResult.ADCRESULT9 * (-0.00865)  + 23.339994;
	PhiMech = M_PI*2*(float)EncPos()/8192.0 -0.269;
	if(PhiMech > (2*M_PI))
	{
	    PhiMech -= 2*M_PI;
	}
	if(PhiMech < 0)
	{
	    PhiMech += 2*M_PI;
	}


	//Zabezpieczenie nadpradowe
	if(praca){
		if((fabs(iB)>3.0) || (fabs(iC)>3.0)){
			praca=0;
			EPwm_Control123(praca);
	    }
	}
	        alfa += (TS * omega_fake);

	        a = -iB - iC;
	        b = iB;
	        c = iC;
	        graphiA[temp] = PI_reg_vel.final_output;
	        temp++;
	        if(temp == 199)
	        {
	            temp = 0;
	        }




//PI_reg_vel.final_output
	        trans_abc_dq_calc(&trans_abc_dq, a, b, c, PhiMech); //transformacja abc-> dq
	        derivative_calc(&drv, PhiMech);
	        PICalc(&PI_reg_vel, rpm , drv.output);
	        PICalc(&PI_reg_iq, PI_reg_vel.final_output, trans_abc_dq.iq);
	        PICalc(&PI_reg_id, 0, trans_abc_dq.id);
	        trans_dq_abc_calc(&trans_dq_abc, PI_reg_id.final_output, PI_reg_iq.final_output, PhiMech); //transformacja dq-> abc
	        mcd_calc(&mak, trans_dq_abc.a, trans_dq_abc.b, trans_dq_abc.c);

	        if(alfa > 2 * M_PI)
	        {
	            alfa -= 2 * M_PI;
	        }
	EPwm1Regs.CMPA.half.CMPA = InvUdc*mak.output_a * (TB_PRD/2) + (TB_PRD/2);
	EPwm2Regs.CMPA.half.CMPA = InvUdc*mak.output_b * (TB_PRD/2) + (TB_PRD/2);
	EPwm3Regs.CMPA.half.CMPA = InvUdc*mak.output_c* (TB_PRD/2) + (TB_PRD/2);


	AdcIntCounter++;

	AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;     //Clear ADCINT1 flag reinitialize for next SOC
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
}


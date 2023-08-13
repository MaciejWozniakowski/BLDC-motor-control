/*
 * PI.c
 *
 *  Created on: 22 maj 2023
 *      Author: student
 */


#include "PI.h"
#include "math.h"

void PIInit(struct PI *pi, float Ts, float Kr, float Ti, float max, float min){
    pi->y=0;
    pi->x=0;
    pi->y_1=0;
    pi->x_1 = 0;
    pi->Kr=Kr;
    pi->Ts_PI=Ts;
    pi->Ti=Ti;
    pi->integ = 0;
    pi->final_output = 0;
    pi->integ_1 = 0;
    pi->final_output_before = 0;
    pi->max = max;
    pi->min = min;

}

void PICalc(struct PI *pi, float x, float feedback){
    pi->x=x - feedback;

    if (pi->final_output_before < pi->max && pi->final_output_before > pi->min)
    {
        pi->integ=(((pi->Ts_PI/pi->Ti * pi->x * pi->Kr) / 2.0) + ((pi->Ts_PI/pi->Ti * pi->x_1 * pi->Kr) / 2.0) +  pi->integ_1);

    }
    else
    {
        pi->integ = pi->integ_1;
    }

    pi->final_output = pi->Kr*pi->x + pi->integ;
    if(pi->final_output >= pi->max)
    {
        pi->final_output = pi->max;
    }
    else if(pi->final_output <= pi->min)
    {
        pi->final_output = pi->min;
    }
    pi->x_1 = pi->x;
    pi->integ_1 = pi->integ;
    pi->y_1=pi->final_output;
    pi->final_output_before = pi->final_output;
}

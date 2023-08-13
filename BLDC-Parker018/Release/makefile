################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./DSP2833x_ADC_cal.obj" \
"./PI.obj" \
"./abcdq.obj" \
"./derivative.obj" \
"./dqabc.obj" \
"./funkcje.obj" \
"./mainBLDC.obj" \
"./mcd.obj" \
"./source/DSP280x_Spi.obj" \
"./source/F2806x_Adc.obj" \
"./source/F2806x_CodeStartBranch.obj" \
"./source/F2806x_CpuTimers.obj" \
"./source/F2806x_DefaultIsr.obj" \
"./source/F2806x_GlobalVariableDefs.obj" \
"./source/F2806x_Gpio.obj" \
"./source/F2806x_MemCopy.obj" \
"./source/F2806x_PieCtrl.obj" \
"./source/F2806x_PieVect.obj" \
"./source/F2806x_SysCtrl.obj" \
"./source/F2806x_usDelay.obj" \
"../28069_RAM_lnk.cmd" \
"../F2806x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include source/subdir_vars.mk
-include subdir_rules.mk
-include source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
BLDC-Parker018.out \

EXE_OUTPUTS__QUOTED += \
"BLDC-Parker018.out" \


# All Target
all: BLDC-Parker018.out

# Tool invocations
BLDC-Parker018.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 -O2 --diag_warning=225 --display_error_number --diag_wrap=off -z --stack_size=0x300 -m"BLDC-Parker018.map" --warn_sections -i"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/lib" -i"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" --reread_libs --display_error_number --diag_wrap=off --xml_link_info="BLDC-Parker018_linkInfo.xml" --rom_model -o "BLDC-Parker018.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "DSP2833x_ADC_cal.obj" "PI.obj" "abcdq.obj" "derivative.obj" "dqabc.obj" "funkcje.obj" "mainBLDC.obj" "mcd.obj" "source\DSP280x_Spi.obj" "source\F2806x_Adc.obj" "source\F2806x_CodeStartBranch.obj" "source\F2806x_CpuTimers.obj" "source\F2806x_DefaultIsr.obj" "source\F2806x_GlobalVariableDefs.obj" "source\F2806x_Gpio.obj" "source\F2806x_MemCopy.obj" "source\F2806x_PieCtrl.obj" "source\F2806x_PieVect.obj" "source\F2806x_SysCtrl.obj" "source\F2806x_usDelay.obj" 
	-$(RM) "PI.d" "abcdq.d" "derivative.d" "dqabc.d" "funkcje.d" "mainBLDC.d" "mcd.d" "source\DSP280x_Spi.d" "source\F2806x_Adc.d" "source\F2806x_CpuTimers.d" "source\F2806x_DefaultIsr.d" "source\F2806x_GlobalVariableDefs.d" "source\F2806x_Gpio.d" "source\F2806x_MemCopy.d" "source\F2806x_PieCtrl.d" "source\F2806x_PieVect.d" "source\F2806x_SysCtrl.d" 
	-$(RM) "DSP2833x_ADC_cal.d" "source\F2806x_CodeStartBranch.d" "source\F2806x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


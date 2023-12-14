#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Calculator_Math/CalculatorMath.c ECU_Layer/ECU_Button/ECU_Button.c ECU_Layer/ECU_keypad/ECU_keypad.c ECU_Layer/ECU_LCD/ECU_LCD.c ECU_Layer/ECU_init.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/mcal_I2C/hal_I2C.c MCAL_Layer/mcal_interrupt/interrupt_manager.c MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c MCAL_Layer/device_config.c Calculator.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ${OBJECTDIR}/ECU_Layer/ECU_init.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Calculator.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d ${OBJECTDIR}/Calculator.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ${OBJECTDIR}/ECU_Layer/ECU_init.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Calculator.p1

# Source Files
SOURCEFILES=Calculator_Math/CalculatorMath.c ECU_Layer/ECU_Button/ECU_Button.c ECU_Layer/ECU_keypad/ECU_keypad.c ECU_Layer/ECU_LCD/ECU_LCD.c ECU_Layer/ECU_init.c MCAL_Layer/GPIO/hal_gpio.c MCAL_Layer/mcal_I2C/hal_I2C.c MCAL_Layer/mcal_interrupt/interrupt_manager.c MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c MCAL_Layer/device_config.c Calculator.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Calculator_Math/CalculatorMath.p1: Calculator_Math/CalculatorMath.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Calculator_Math" 
	@${RM} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d 
	@${RM} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 Calculator_Math/CalculatorMath.c 
	@-${MV} ${OBJECTDIR}/Calculator_Math/CalculatorMath.d ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1: ECU_Layer/ECU_Button/ECU_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 ECU_Layer/ECU_Button/ECU_Button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.d ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1: ECU_Layer/ECU_keypad/ECU_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 ECU_Layer/ECU_keypad/ECU_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.d ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1: ECU_Layer/ECU_LCD/ECU_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ECU_Layer/ECU_LCD/ECU_LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_init.p1: ECU_Layer/ECU_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_init.p1 ECU_Layer/ECU_init.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_init.d ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1: MCAL_Layer/mcal_I2C/hal_I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 MCAL_Layer/mcal_I2C/hal_I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.d ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1: MCAL_Layer/mcal_interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 MCAL_Layer/mcal_interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1: MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1: MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Calculator.p1: Calculator.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Calculator.p1.d 
	@${RM} ${OBJECTDIR}/Calculator.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Calculator.p1 Calculator.c 
	@-${MV} ${OBJECTDIR}/Calculator.d ${OBJECTDIR}/Calculator.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Calculator.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Calculator_Math/CalculatorMath.p1: Calculator_Math/CalculatorMath.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Calculator_Math" 
	@${RM} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d 
	@${RM} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1 Calculator_Math/CalculatorMath.c 
	@-${MV} ${OBJECTDIR}/Calculator_Math/CalculatorMath.d ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Calculator_Math/CalculatorMath.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1: ECU_Layer/ECU_Button/ECU_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_Button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1 ECU_Layer/ECU_Button/ECU_Button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.d ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_Button/ECU_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1: ECU_Layer/ECU_keypad/ECU_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1 ECU_Layer/ECU_keypad/ECU_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.d ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_keypad/ECU_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1: ECU_Layer/ECU_LCD/ECU_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ECU_Layer/ECU_LCD/ECU_LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_init.p1: ECU_Layer/ECU_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_init.p1 ECU_Layer/ECU_init.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_init.d ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1: MCAL_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1 MCAL_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1: MCAL_Layer/mcal_I2C/hal_I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1 MCAL_Layer/mcal_I2C/hal_I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.d ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_I2C/hal_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1: MCAL_Layer/mcal_interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1 MCAL_Layer/mcal_interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1: MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1 MCAL_Layer/mcal_interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1: MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/mcal_interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1 MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/mcal_interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Calculator.p1: Calculator.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Calculator.p1.d 
	@${RM} ${OBJECTDIR}/Calculator.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Calculator.p1 Calculator.c 
	@-${MV} ${OBJECTDIR}/Calculator.d ${OBJECTDIR}/Calculator.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Calculator.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Calculator.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Calculator.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Calculator.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Calculator.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

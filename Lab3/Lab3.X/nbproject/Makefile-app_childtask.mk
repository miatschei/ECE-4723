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
ifeq "$(wildcard nbproject/Makefile-local-app_childtask.mk)" "nbproject/Makefile-local-app_childtask.mk"
include nbproject/Makefile-local-app_childtask.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=app_childtask
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../esos/src/esos.c ../../esos/src/esos_comm.c ../../esos/src/pic24/esos_pic24_irq.c ../../esos/src/pic24/esos_pic24_rs232.c ../../esos/src/pic24/esos_pic24_tick.c ../../esos/src/pic24/esos_pic24_i2c.c ../../esos/src/pic24/esos_pic24_spi.c ../../esos/src/esos_cb.c ../../esos/src/esos_mail.c ../traffic_t1.c ../../lib/src/pic24_clockfreq.c ../../lib/src/pic24_configbits.c ../../lib/src/pic24_adc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1022787335/esos.o ${OBJECTDIR}/_ext/1022787335/esos_comm.o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o ${OBJECTDIR}/_ext/1022787335/esos_cb.o ${OBJECTDIR}/_ext/1022787335/esos_mail.o ${OBJECTDIR}/_ext/1472/traffic_t1.o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o ${OBJECTDIR}/_ext/957557178/pic24_adc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1022787335/esos.o.d ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d ${OBJECTDIR}/_ext/1022787335/esos_cb.o.d ${OBJECTDIR}/_ext/1022787335/esos_mail.o.d ${OBJECTDIR}/_ext/1472/traffic_t1.o.d ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1022787335/esos.o ${OBJECTDIR}/_ext/1022787335/esos_comm.o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o ${OBJECTDIR}/_ext/1022787335/esos_cb.o ${OBJECTDIR}/_ext/1022787335/esos_mail.o ${OBJECTDIR}/_ext/1472/traffic_t1.o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o ${OBJECTDIR}/_ext/957557178/pic24_adc.o

# Source Files
SOURCEFILES=../../esos/src/esos.c ../../esos/src/esos_comm.c ../../esos/src/pic24/esos_pic24_irq.c ../../esos/src/pic24/esos_pic24_rs232.c ../../esos/src/pic24/esos_pic24_tick.c ../../esos/src/pic24/esos_pic24_i2c.c ../../esos/src/pic24/esos_pic24_spi.c ../../esos/src/esos_cb.c ../../esos/src/esos_mail.c ../traffic_t1.c ../../lib/src/pic24_clockfreq.c ../../lib/src/pic24_configbits.c ../../lib/src/pic24_adc.c


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
	${MAKE}  -f nbproject/Makefile-app_childtask.mk dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512GP806
MP_LINKER_FILE_OPTION=,--script=p33EP512GP806.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1022787335/esos.o: ../../esos/src/esos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos.c  -o ${OBJECTDIR}/_ext/1022787335/esos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_comm.o: ../../esos/src/esos_comm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_comm.c  -o ${OBJECTDIR}/_ext/1022787335/esos_comm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o: ../../esos/src/pic24/esos_pic24_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_irq.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o: ../../esos/src/pic24/esos_pic24_rs232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_rs232.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o: ../../esos/src/pic24/esos_pic24_tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_tick.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o: ../../esos/src/pic24/esos_pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_i2c.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o: ../../esos/src/pic24/esos_pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_spi.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_cb.o: ../../esos/src/esos_cb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_cb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_cb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_cb.c  -o ${OBJECTDIR}/_ext/1022787335/esos_cb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_cb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_cb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_mail.o: ../../esos/src/esos_mail.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_mail.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_mail.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_mail.c  -o ${OBJECTDIR}/_ext/1022787335/esos_mail.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_mail.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_mail.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/traffic_t1.o: ../traffic_t1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/traffic_t1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/traffic_t1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../traffic_t1.c  -o ${OBJECTDIR}/_ext/1472/traffic_t1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/traffic_t1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/traffic_t1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o: ../../lib/src/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_configbits.o: ../../lib/src/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_adc.o: ../../lib/src/pic24_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/957557178/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1022787335/esos.o: ../../esos/src/esos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos.c  -o ${OBJECTDIR}/_ext/1022787335/esos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_comm.o: ../../esos/src/esos_comm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_comm.c  -o ${OBJECTDIR}/_ext/1022787335/esos_comm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o: ../../esos/src/pic24/esos_pic24_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_irq.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o: ../../esos/src/pic24/esos_pic24_rs232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_rs232.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o: ../../esos/src/pic24/esos_pic24_tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_tick.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o: ../../esos/src/pic24/esos_pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_i2c.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o: ../../esos/src/pic24/esos_pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/750133316" 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_spi.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_cb.o: ../../esos/src/esos_cb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_cb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_cb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_cb.c  -o ${OBJECTDIR}/_ext/1022787335/esos_cb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_cb.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_cb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_mail.o: ../../esos/src/esos_mail.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1022787335" 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_mail.o.d 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_mail.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_mail.c  -o ${OBJECTDIR}/_ext/1022787335/esos_mail.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_mail.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_mail.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/traffic_t1.o: ../traffic_t1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/traffic_t1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/traffic_t1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../traffic_t1.c  -o ${OBJECTDIR}/_ext/1472/traffic_t1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/traffic_t1.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/traffic_t1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o: ../../lib/src/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_configbits.o: ../../lib/src/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_configbits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_configbits.c  -o ${OBJECTDIR}/_ext/957557178/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/957557178/pic24_adc.o: ../../lib/src/pic24_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/957557178" 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/957557178/pic24_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/src/pic24_adc.c  -o ${OBJECTDIR}/_ext/957557178/pic24_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d"      -mno-eds-warn  -g -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -DBUILT_ON_ESOS -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/957557178/pic24_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -DBUILT_ON_ESOS -DXPRJ_app_childtask=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Lab3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/app_childtask
	${RM} -r dist/app_childtask

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

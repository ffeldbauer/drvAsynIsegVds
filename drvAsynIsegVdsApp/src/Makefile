TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

DBD += drvAsynIsegVds.dbd

LIBRARY_IOC += drvAsynIsegVds

drvAsynIsegVds_SRCS += drvAsynIsegVds.cpp
drvAsynIsegVds_SRCS += VmeMaster.cpp
drvAsynIsegVds_LIBS += $(EPICS_BASE_IOC_LIBS)

drvAsynIsegVds_DBD += base.dbd
drvAsynIsegVds_DBD += asyn.dbd
drvAsynIsegVds_DBD += isegVds.dbd

ifneq ($(words $(SIS3100_LIB) $(SIS3100_INCLUDE)),0)
drvAsynIsegVds_SRCS += VmeMasterSIS3100.cpp
VmeMasterSIS3100_INCLUDES += -I$(SIS3100_INCLUDE)
drvAsynIsegVds_SYS_LIBS += _sis3100
drvAsynIsegVds_DBD += sis3100.dbd
SHRLIB_DEPLIB_DIRS += $(SIS3100_LIB)
endif

#=============================

PROD_IOC += drvAsynIsegVdsTest

# drvAsynIsegVds_registerRecordDeviceDriver.cpp will be created from drvAsynIsegVds.dbd
drvAsynIsegVdsTest_SRCS += drvAsynIsegVds_registerRecordDeviceDriver.cpp
drvAsynIsegVdsTest_SRCS_DEFAULT += drvAsynIsegVdsMain.cpp

drvAsynIsegVdsTest_LIBS += drvAsynIsegVds asyn
drvAsynIsegVdsTest_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


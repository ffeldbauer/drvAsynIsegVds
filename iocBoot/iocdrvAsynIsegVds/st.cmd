#!../../bin/linux-x86_64/drvAsynIsegVdsTest

< envPaths

## Register all support components
dbLoadDatabase "$(TOP)/dbd/drvAsynIsegVds.dbd"
drvAsynIsegVds_registerRecordDeviceDriver pdbbase

## Load ISEG VDS driver
drvAsynIsegVdsConfigure( "isegvds0", "/tmp/sis1100", 0x4000 )

## Load record instances
dbLoadRecords( "$(TOP)/db/iseg_vds.db", "" )

cd ${TOP}/iocBoot/${IOC}
iocInit

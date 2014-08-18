drvAsynIsegVds
==============

EPICS device support Module for ISEG VDS high voltage power supplies via SIS1100/3100 PCI-VME.
AsynPortDriver to controll a ISEG VDS high voltage VME module.

Currently only the SIS1100/3100 optical PCI-VME link is supported. An additional abstraction layer
will be implemented in a later version, to create a flexible interface to other VME controller.

Dependencies
============

  - EPICS base 3.14.12.4 or later (http://www.aps.anl.gov/epics/)
  - AsynDriver 4-22 or later (http://www.aps.anl.gov/epics/modules/soft/asyn/)
  - SIS1100/3100 Linux Driver and SIS3100 library

By default EPICS builds shared libraries. The SIS3100 on the otherside is build as static library.
Either change the settings in <EPICSbase>/configure/CONFIG_SITE to build static libraries,
or modify the Makefile of the SIS3100 library to build a shared library.

Install
=======

  1. Edit 'configure/RELEASE' and change the paths to ASYN and EPICS_BASE
  2. Edit 'configure/RELEASE.Common.<Target>' and set SIS3100_INCLUDE and SIS3100_LIB to the paths of the SIS3100 support
     header and library
  3. Type `make` to compile the package.

Usage
=====

Refer to "documentation/drvAsynIsegVds.html" for more information
on how to use the asynPortDriver

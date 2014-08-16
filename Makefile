# Makefile for Asyn drvAsynIsegVDS support
#
# Created by florian on Fri Aug 15 15:38:08 2014
# Based on the Asyn app template

TOP = .
include $(TOP)/configure/CONFIG

DIRS := configure
DIRS += $(wildcard *[Ss]up)
DIRS += $(wildcard *[Aa]pp)
DIRS += $(wildcard ioc[Bb]oot)

include $(TOP)/configure/RULES_TOP

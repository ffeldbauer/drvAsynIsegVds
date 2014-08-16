//******************************************************************************
// Copyright (C) 2014 Florian Feldbauer <florian@ep1.ruhr-uni-bochum.de>
//                    - Helmholtz-Institut/University Mainz, Institute for nuclear physics
//
// This file is part of drvAsynIsegVds
//
// drvAsynIsegVds is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// drvAsynIsegVds is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
// version 1.0.0; Aug. 15, 2014
//******************************************************************************

#ifndef __ASYN_ISEG_VDS_H__
#define __ASYN_ISEG_VDS_H__

//_____ I N C L U D E S _______________________________________________________
#include <map>
#include "asynPortDriver.h"

//_____ D E F I N I T I O N S __________________________________________________

/* These are the drvInfo strings that are used to identify the parameters.
 * They are used by asyn clients, including standard asyn device support */
#define P_ISEGVDS_MODSTATUS_STRING         "ModuleStatus"             /* asynUInt32Digital,  r   */
#define P_ISEGVDS_MODEVTSTATUS_STRING      "ModuleEventStatus"        /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODEVTMASK_STRING        "ModuleEventMask"          /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODCTRL_STRING           "ModuleControl"            /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODEVTCHANSTATUS_STRING  "ModuleEventChannelStatus" /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODEVTCHANMASK_STRING    "ModuleEventChannelMask"   /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODEVTGRPSTATUS_STRING   "ModuleEventGroupStatus"   /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_MODEVTGRPMASK_STRING     "ModuleEventGroupMask"     /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_VRAMP_STRING             "VoltageRampSpeed"         /* asynFloat64,        r/w */
#define P_ISEGVDS_CRAMP_STRING             "CurrentRampSpeed"         /* asynFloat64,        r/w */
#define P_ISEGVDS_VMAX_STRING              "VoltageMax"               /* asynFloat64,        r   */
#define P_ISEGVDS_IMAX_STRING              "CurrentMax"               /* asynFloat64,        r   */
#define P_ISEGVDS_SUPPLYP5_STRING          "SupplyP5"                 /* asynFloat64,        r   */
#define P_ISEGVDS_SUPPLYP12_STRING         "SupplyP12"                /* asynFloat64,        r   */
#define P_ISEGVDS_SUPPLYN12_STRING         "SupplyN12"                /* asynFloat64,        r   */
#define P_ISEGVDS_TEMPERATURE_STRING       "Temperature"              /* asynFloat64,        r   */
#define P_ISEGVDS_CHANSTATUS_STRING        "ChannelStatus"            /* asynUInt32Digital,  r   */
#define P_ISEGVDS_CHANEVTSTATUS_STRING     "ChannelEventStatus"       /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_CHANEVTMASK_STRING       "ChannelEventMask"         /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_CHANCTRL_STRING          "ChannelCtrl"              /* asynUInt32Digital,  r/w */
#define P_ISEGVDS_CHANVSET_STRING          "VoltageSet"               /* asynFloat64,        r/w */
#define P_ISEGVDS_CHANISET_STRING          "CurrentSet"               /* asynFloat64,        r/w */
#define P_ISEGVDS_CHANVMOM_STRING          "VoltageMeasure"           /* asynFloat64,        r   */
#define P_ISEGVDS_CHANIMOM_STRING          "CurrentMeasure"           /* asynFloat64,        r   */
#define P_ISEGVDS_CHANVBOUNDS_STRING       "VoltageBounds"            /* asynFloat64,        r/w */
#define P_ISEGVDS_CHANIBOUNDS_STRING       "CurrentBounds"            /* asynFloat64,        r/w */

//! @brief   asynPortDriver for ISEG VDS high voltage modules
//!
//! This asynPortDriver is used as device support for the
//! VDS high voltage modules of ISEG Spezialelektronik GmbH.
class drvAsynIsegVds : public asynPortDriver {
 public:
  drvAsynIsegVds( const char *portName, const char *vmedev, const int BA );

  /* These are the methods that we override from asynPortDriver */
  virtual asynStatus readUInt32Digital( asynUser *pasynUser, epicsUInt32 *value, epicsUInt32 mask );
  virtual asynStatus writeUInt32Digital( asynUser *pasynUser, epicsUInt32 value, epicsUInt32 mask );
  virtual asynStatus writeFloat64( asynUser *pasynUser, epicsFloat64 value );
  virtual asynStatus readFloat64( asynUser *pasynUser, epicsFloat64 *value );

 protected:
  /* Values used for pasynUser->reason, and indexes into the parameter library. */
  int P_ModStatus;         //!< index of Parameter "ModuleStatus"
  int P_ModEvtStatus;      //!< index of Parameter "ModuleEventStatus"
  int P_ModEvtMask;        //!< index of Parameter "ModuleEventMask"
  int P_ModCtrl;           //!< index of Parameter "ModuleControl"
  int P_ModEvtChanStatus;  //!< index of Parameter "ModuleEventChannelStatus"
  int P_ModEvtChanMask;    //!< index of Parameter "ModuleEventChannelMask"
  int P_ModEvtGrpStatus;   //!< index of Parameter "ModuleEventGroupStatus"
  int P_ModEvtGrpMask;     //!< index of Parameter "ModuleEventGroupMask"
  int P_VRamp;             //!< index of Parameter "VoltageRampSpeed"
  int P_CRamp;             //!< index of Parameter "CurrentRampSpeed"
  int P_VMax;              //!< index of Parameter "VoltageMax"
  int P_IMax;              //!< index of Parameter "CurrentMax"
  int P_SupplyP5;          //!< index of Parameter "SupplyP5"
  int P_SupplyP12;         //!< index of Parameter "SupplyP12"
  int P_SupplyN12;         //!< index of Parameter "SupplyN12"
  int P_Temperature;       //!< index of Parameter "Temperature"
  int P_ChanStatus;        //!< index of Parameter "ChannelStatus"
  int P_ChanEvtStatus;     //!< index of Parameter "ChannelEventStatus"
  int P_ChanEvtMask;       //!< index of Parameter "ChannelEventMask"
  int P_ChanCtrl;          //!< index of Parameter "ChannelControl"
  int P_ChanVset;          //!< index of Parameter "VoltageSet"
  int P_ChanIset;          //!< index of Parameter "CurrentSet"
  int P_ChanVmom;          //!< index of Parameter "VoltageMeasure"
  int P_ChanImom;          //!< index of Parameter "CurrentMeasure"
  int P_ChanVBounds;       //!< index of Parameter "VoltageBounds"
  int P_ChanIBounds;       //!< index of Parameter "CurrentBounds"

#define FIRST_ISEGVDS_COMMAND P_ModStatus
#define LAST_ISEGVDS_COMMAND  P_ChanImom

 private:
  std::map<int, epicsUInt32> chancmds_;
  std::map<int, epicsUInt32> modcmds_;

  char                *deviceName_;
  epicsUInt32          base_;
  int                  fd_;

};

#define NUM_ISEGVDS_PARAMS (&LAST_ISEGVDS_COMMAND - &FIRST_ISEGVDS_COMMAND + 1)

#endif

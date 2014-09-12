//******************************************************************************
// Copyright (C) 2014 Florian Feldbauer <florian@ep1.ruhr-uni-bochum.de>
//                    - Helmholtz-Institut/University Mainz, Institute for nuclear physics
//                    Matthias Steinke <matthias@ep1.ruhr-uni-bochum.de>
//                    - University Bochum, Intitue for experimental physics I
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
// version 1.5.0; Sep. 11, 2014
//******************************************************************************

#pragma once

//_____ I N C L U D E S _______________________________________________________
#include <cctype>
#include <cstdio>
#include <stdint.h>

#include "VmeMaster.h"

//_____ D E F I N I T I O N S __________________________________________________

//! @brief   Interface to SIS1100/3100 PCI-VME controller
//!
//! This class implements the VME functions for the SIS1100/3100 optical
//! PCI-VME link
class VmeMasterSIS3100 : public VmeMaster {
 public: 
  static void create( const char* );

  // A16
  void     writeRegisterA16D8  ( uint32_t, uint32_t, uint8_t  );
  void     writeRegisterA16D16 ( uint32_t, uint32_t, uint16_t );
  void     writeRegisterA16D32 ( uint32_t, uint32_t, uint32_t );
  uint8_t  readRegisterA16D8   ( uint32_t, uint32_t );
  uint16_t readRegisterA16D16  ( uint32_t, uint32_t );
  uint32_t readRegisterA16D32  ( uint32_t, uint32_t );

  // A24
  void     writeRegisterA24D8  ( uint32_t, uint32_t, uint8_t  );
  void     writeRegisterA24D16 ( uint32_t, uint32_t, uint16_t );
  void     writeRegisterA24D32 ( uint32_t, uint32_t, uint32_t );
  uint8_t  readRegisterA24D8   ( uint32_t, uint32_t );
  uint16_t readRegisterA24D16  ( uint32_t, uint32_t );
  uint32_t readRegisterA24D32  ( uint32_t, uint32_t );

  // A32
  void     writeRegisterA32D8  ( uint32_t, uint32_t, uint8_t  );
  void     writeRegisterA32D16 ( uint32_t, uint32_t, uint16_t );
  void     writeRegisterA32D32 ( uint32_t, uint32_t, uint32_t );
  uint8_t  readRegisterA32D8   ( uint32_t, uint32_t );
  uint16_t readRegisterA32D16  ( uint32_t, uint32_t );
  uint32_t readRegisterA32D32  ( uint32_t, uint32_t );

  int32_t  fifoBltRead( uint32_t, uint32_t, uint32_t, uint32_t* );
  int32_t  bltRead( uint32_t, uint32_t, uint32_t, uint32_t* );

 private:
  VmeMasterSIS3100();
  VmeMasterSIS3100( const char* );
  VmeMasterSIS3100( const VmeMasterSIS3100& rother );
  virtual ~VmeMasterSIS3100();

  int32_t  _sisHandle;

}; 


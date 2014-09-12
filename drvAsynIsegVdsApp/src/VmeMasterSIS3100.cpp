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
// brief   Interface for SIS1100/3100 PCI-VME controller
//
// version 1.5.0; Sep. 11, 2014
//******************************************************************************

//_____ I N C L U D E S _______________________________________________________

// ANSI C/C++ includes
#include <iostream>
#include <cerrno>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sis3100_vme_calls.h>

// EPICS includes
#include <epicsExport.h>
#include <iocsh.h>

// local includes
#include "VmeMasterSIS3100.h"

//_____ D E F I N I T I O N S __________________________________________________

//_____ G L O B A L S __________________________________________________________

//_____ L O C A L S ____________________________________________________________

//_____ F U N C T I O N S ______________________________________________________

//------------------------------------------------------------------------------
VmeMasterSIS3100::VmeMasterSIS3100()
  : VmeMaster()
{}

//------------------------------------------------------------------------------
VmeMasterSIS3100::VmeMasterSIS3100( const char* devName )
  : VmeMaster()
{
  if( ( _sisHandle = open( devName, O_RDWR, 0 ) ) < 0 ) {
    std::cerr << "open of " << devName << " failed" << std::endl;
    exit(1);
  }

  unsigned int value = 0xffffffff;
  int result;
  result = s3100_control_read( _sisHandle, 0x12000000 + 0, &value );
  //  std::cerr << "SIS3100: 0 " << std::hex << value << " return code " << result << std::endl;
  result = s3100_control_read( _sisHandle, 0x12000000 + 4, &value );
  //  std::cerr << "SIS3100: 4 " << std::hex << value << " return code " << result << std::dec << std::endl;
}

//------------------------------------------------------------------------------
VmeMasterSIS3100::~VmeMasterSIS3100() {
  close( _sisHandle );
}

//------------------------------------------------------------------------------
VmeMasterSIS3100::VmeMasterSIS3100( const VmeMasterSIS3100& rother ) {}

//------------------------------------------------------------------------------
//! @brief   Creates an instance of class VmeMasterSIS3100
//! @param   [in] devName  file system name of device
//------------------------------------------------------------------------------
void VmeMasterSIS3100::create( const char* devName ) {
  if ( _pinstance )
    std::cerr << "VME Singleton has already been created" << std::endl;
  else
    _pinstance = new VmeMasterSIS3100( devName );
}

//------------------------------------------------------------------------------

void VmeMasterSIS3100::writeRegisterA16D8 ( uint32_t baseAddress, uint32_t subAddress, uint8_t value ) {
  if( vme_A16D8_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA16D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) {
  if( vme_A16D16_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA16D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) {
  if( vme_A16D32_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
uint8_t VmeMasterSIS3100::readRegisterA16D8 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint8_t value = 0xff;
  if( vme_A16D8_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint16_t VmeMasterSIS3100::readRegisterA16D16 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint16_t value = 0xff;
  if( vme_A16D16_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint32_t VmeMasterSIS3100::readRegisterA16D32 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint32_t value = 0xff;
  if( vme_A16D32_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
void VmeMasterSIS3100::writeRegisterA24D8 ( uint32_t baseAddress, uint32_t subAddress, uint8_t value ) {
  if( vme_A24D8_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA24D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) {
  if( vme_A24D16_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA24D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) {
  if( vme_A24D32_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
uint8_t VmeMasterSIS3100::readRegisterA24D8 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint8_t value = 0xff;
  if( vme_A24D8_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint16_t VmeMasterSIS3100::readRegisterA24D16 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint16_t value = 0xff;
  if( vme_A24D16_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint32_t VmeMasterSIS3100::readRegisterA24D32 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint32_t value = 0xff;
  if( vme_A24D32_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
void VmeMasterSIS3100::writeRegisterA32D8 ( uint32_t baseAddress, uint32_t subAddress, uint8_t value ) {
  if( vme_A32D8_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA32D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) {
  if( vme_A32D16_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
void VmeMasterSIS3100::writeRegisterA32D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) {
  if( vme_A32D32_write( _sisHandle, baseAddress + subAddress, value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not write to VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
}
uint8_t VmeMasterSIS3100::readRegisterA32D8 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint8_t value = 0xff;
  if( vme_A32D8_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint16_t VmeMasterSIS3100::readRegisterA32D16 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint16_t value = 0xff;
  if( vme_A32D16_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}
uint32_t VmeMasterSIS3100::readRegisterA32D32 ( uint32_t baseAddress, uint32_t subAddress ) {
  uint32_t value = 0xff;
  if( vme_A32D32_read( _sisHandle, baseAddress + subAddress, &value ) != 0 ) {
    char errmsg[255];
    sprintf( errmsg, "Could not read from VMEbus: %s(%d)", strerror( errno ), errno );
    throw VmeException( errmsg );
  }
  return value;
}

//------------------------------------------------------------------------------

int32_t VmeMasterSIS3100::fifoBltRead( uint32_t baseAddress, uint32_t subAddress, 
                                       uint32_t wordsToRead, uint32_t* buffer ) {
  uint32_t result = 0;
  int32_t  status;
  uint32_t rest;
  unsigned int transfered = 0;
  unsigned int wordsToTransfer;
  
  rest = wordsToRead;
  while( rest > 0 ) {
    wordsToTransfer = (rest <= 8196) ? rest : 8196;
    if ((status = vme_A32BLT32FIFO_read(_sisHandle, baseAddress + subAddress, 
                                        &buffer[transfered], wordsToTransfer, &result)) < 0) {
      std::cerr << "SIS3100 vme_A32BLT32_read failed with " << status << std::endl;
      std::cerr << "got " << result << " words" << std::endl;
      exit(1);
    }
    rest -= result;
    transfered += result;
  }

  return transfered;
}

//------------------------------------------------------------------------------

int32_t VmeMasterSIS3100::bltRead( uint32_t baseAddress, uint32_t subAddress, 
                                   uint32_t wordsToRead, uint32_t* buffer ) {
  uint32_t result = 0;
  int32_t  status;
  unsigned int rest;
  unsigned int transfered = 0;
  unsigned int wordsToTransfer;
  
  rest = wordsToRead;
  while (rest > 0) {
    wordsToTransfer = (rest < 8192) ? rest : 8192;
    if ((status = vme_A32BLT32_read( _sisHandle, baseAddress + subAddress, 
                                     &buffer[transfered], wordsToTransfer, &result)) < 0) {
      std::cerr << "SIS3100 vme_A32BLT32_read failed with " << status << std::endl;
      std::cerr << "got " << result << " words" << std::endl;
      exit(1);
    }
    rest -= result;
    transfered += result;
  }

  return transfered;
}

// Configuration routines. Called directly, or from the iocsh function below
extern "C" {
  
  //----------------------------------------------------------------------------
  //! @brief   EPICS iocsh callable function to call constructor
  //!          for the VmeMasterSIS3100 class.
  //!
  //! @param  [in]  vmedev   The name of the VME crate on the device file system
  //----------------------------------------------------------------------------
  int SIS3100Configure( const char *vmedev ) {
    VmeMasterSIS3100::create( vmedev );
    return 0;
  }
  static const iocshArg initSis3100Arg0 = { "vmedev", iocshArgString };
  static const iocshArg * const initSis3100Args[] = { &initSis3100Arg0 };
  static const iocshFuncDef initSis3100FuncDef = { "SIS3100Configure", 1, initSis3100Args };
  static void initSis3100CallFunc( const iocshArgBuf *args ) {
    SIS3100Configure( args[0].sval );
  }
  
  //----------------------------------------------------------------------------
  //! @brief   Register functions to EPICS
  //----------------------------------------------------------------------------
  void Sis3100DrvRegister( void ) {
    static int firstTime = 1;
    if ( firstTime ) {
      iocshRegister( &initSis3100FuncDef, initSis3100CallFunc );
      firstTime = 0;
    }
  }
  
  epicsExportRegistrar( Sis3100DrvRegister );
}

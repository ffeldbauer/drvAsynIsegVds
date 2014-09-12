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
// brief   Abstract VmeMaster interface
//
// version 1.5.0; Sep. 11, 2014
//******************************************************************************

//_____ I N C L U D E S _______________________________________________________
#include <iostream>

#include "VmeMaster.h"

//_____ D E F I N I T I O N S __________________________________________________

//_____ G L O B A L S __________________________________________________________
VmeMaster* VmeMaster::_pinstance = NULL; 

//_____ L O C A L S ____________________________________________________________

//_____ F U N C T I O N S ______________________________________________________


VmeMaster::VmeMaster() {}

VmeMaster::~VmeMaster() {}

VmeMaster::VmeMaster( const VmeMaster& rother ) {}

//------------------------------------------------------------------------------
//! @brief   Get pointer to an instance of class VmeMaster 
//! @return  Address of instance 
//------------------------------------------------------------------------------
VmeMaster* VmeMaster::getInstance() { 
  if( !_pinstance )
    std::cerr << "VmeMaster base class has not been created" << std::endl;
  return _pinstance; 
}

//------------------------------------------------------------------------------
//! @brief   Check if an instance exists 
//! @return  true if instance exists, otherwise false
//------------------------------------------------------------------------------
bool VmeMaster::exists() {
  return ( _pinstance != 0 );
}


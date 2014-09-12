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
#include <exception>
#include <cctype>
#include <cstdio>
#include <stdint.h>
#include <string>

//_____ D E F I N I T I O N S __________________________________________________

//! @brief   Abstract interface to VmeMaster
//!
//! This class is used to abstract the actual used
//! VME master.
class VmeMaster {
 public: 
  static VmeMaster* getInstance(); 
  static bool exists();

  //! @{
  //! @brief     Write VME registers with 16 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @param     [in]  value        value to write
  //! @exception VmeException       Exception holding error message if write cmd failed
  virtual void     writeRegisterA16D8  ( uint32_t baseAddress, uint32_t subAddress, uint8_t  value ) = 0;
  virtual void     writeRegisterA16D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) = 0;
  virtual void     writeRegisterA16D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) = 0;
  //! @}

  //! @{
  //! @brief     Read VME registers with 16 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @return    data read from register
  //! @exception VmeException       Exception holding error message if read cmd failed
  virtual uint8_t  readRegisterA16D8   ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint16_t readRegisterA16D16  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint32_t readRegisterA16D32  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  //! @}

  //! @{
  //! @brief     Write VME registers with 24 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @param     [in]  value        value to write
  //! @exception VmeException       Exception holding error message if read cmd failed
  virtual void     writeRegisterA24D8  ( uint32_t baseAddress, uint32_t subAddress, uint8_t  value ) = 0;
  virtual void     writeRegisterA24D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) = 0;
  virtual void     writeRegisterA24D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) = 0;
  //! @}

  //! @{
  //! @brief     Read VME registers with 16 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @return    data read from register
  //! @exception VmeException       Exception holding error message if read cmd failed
  virtual uint8_t  readRegisterA24D8   ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint16_t readRegisterA24D16  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint32_t readRegisterA24D32  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  //! @}

  //! @{
  //! @brief     Write VME registers with 32 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @param     [in]  value        value to write
  //! @exception VmeException       Exception holding error message if read cmd failed
  virtual void     writeRegisterA32D8  ( uint32_t baseAddress, uint32_t subAddress, uint8_t  value ) = 0;
  virtual void     writeRegisterA32D16 ( uint32_t baseAddress, uint32_t subAddress, uint16_t value ) = 0;
  virtual void     writeRegisterA32D32 ( uint32_t baseAddress, uint32_t subAddress, uint32_t value ) = 0;
  //! @}

  //! @{
  //! @brief     Read VME registers with 16 bit address length
  //! @param     [in]  baseAddress  base address of a VME module
  //! @param     [in]  subAddress   address of register relative to base address
  //! @return    data read from register
  //! @exception VmeException       Exception holding error message if read cmd failed
  virtual uint8_t  readRegisterA32D8   ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint16_t readRegisterA32D16  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  virtual uint32_t readRegisterA32D32  ( uint32_t baseAddress, uint32_t subAddress ) = 0;
  //! @}
 
  //! @brief  ? 
  //! @param  [in]  baseAddress  base address of a VME module
  //! @param  [in]  subAddress   address of register relative to base address
  //! @param  [in]  wordsToRead  ?
  //! @param  [in]  buffer       ?
  //! @return ? 
  virtual int32_t  fifoBltRead( uint32_t baseAddress, uint32_t subAddress, 
                                uint32_t wordsToRead, uint32_t* buffer ) = 0;
  //! @brief  ? 
  //! @param  [in] baseAddress base address of a VME module
  //! @param  [in] subAddress  address of register relative to base address
  //! @param  [in]  wordsToRead  ?
  //! @param  [in]  buffer       ?
  //! @return ? 
  virtual int32_t  bltRead( uint32_t baseAddress, uint32_t subAddress, 
                            uint32_t wordsToRead, uint32_t* buffer ) = 0;

 protected:
  VmeMaster();
  VmeMaster( const VmeMaster& rother );
  virtual ~VmeMaster();

  static VmeMaster* _pinstance;

};


//! @brief   Exception for VME failures
//!
//! This Exception is thrown if an error within
//! the VME communication occures.
class VmeException : public std::exception {
 public:
  VmeException(const char* w = "") throw()
    : _what(w)
  {}

  VmeException(const std::string& w) throw()
    : _what(w)
  {}

  VmeException(const VmeException& e) throw()
    : std::exception(e),
      _what(e._what)
  {}

  VmeException& operator=( const VmeException& rhs ) throw() {
    _what = rhs._what;
    return *this;
  }

  ~VmeException() throw() {}


  //--------------------------------------------------------------------------
  //! @brief   Get error message
  //--------------------------------------------------------------------------
  virtual const char* what() const throw() {
    return _what.c_str();
  }

 protected:
  std::string _what;
};


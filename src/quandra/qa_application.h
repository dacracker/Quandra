/***************************************************************************\
 This file is part of the Quandra Game Engine.
 Copyright 2017 Patrik Jeppsson
 
 Quandra is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 Quandra is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with NyxEngine. If not, see <http://www.gnu.org/licenses/>.
 \***************************************************************************/

#ifndef __QUANDRA_APPLICATON_H__
#define __QUANDRA_APPLICATON_H__

#include "qa_common.h"

#pragma once

QA_EXTERN_C_BEGIN

/** Initialize the game engine. Note: You need to call this
  *  function before you call any other function! This function
  * must only be called once.
  */
qa_int32 QA_API qapp_init(void);

/** Shutdown the game engine
  * This function must be called to cleanup game engine resources
  */
void QA_API qapp_quit(void);

qa_int32 QA_API qapp_exec(void);

QA_EXTERN_C_END

#endif

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

#ifndef __QUANDRA_COMPILER_H__
#define __QUANDRA_COMPILER_H__

#pragma once

/* Compiler macros */
#ifdef _MSC_VER /* Using Microsoft Visual C++ */
#    define QA_CC_MSVC
#endif

/* Using GNU GCC or Mingw? */
#ifdef __GNUC__
#    define QA_CC_GNU
#endif

/* Using clang? */
#ifdef __clang__
#    define NX_CC_CLANG
#endif

/* Is C90 supported by this compiler? */
#if defined(__STDC_VERSION__)
#    define QA_STD_C90
/* Is C99 supported by this compiler? */
#    if(__STDC_VERSION__ >= 199901L)
#        define QA_STD_C99
#        define QA_INLINE static inline /* A modern compiler should support inline properly */
#        if(__STDC_VERSION__ >= 201112L)
#            define QA_STD_C11    /* This compiler supports C11, fancy! */
#        endif
#    else
#        define QA_INLINE static /* inline isn't a keyword in pre-C99 standards */
#    endif
#else
#    define QA_INLINE static /* inline isn't a keyword in pre-C99 standards */
#endif

/* Detect if the compiler supports C++ */
#ifdef __cplusplus
#    define QA_STD_CPP
#endif

#endif

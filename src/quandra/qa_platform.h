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

#ifndef __QUANDRA_PLATFORM_H__
#define __QUANDRA_PLATFORM_H__

#pragma once

#include "qa_compiler.h"
#include "qa_types.h"

/*
 Platform macros
 
 Windows: QA_OS_WIN32
 Windows 64-bit: QA_OS_WIN64
 
 Linux: QA_OS_LINUX
 Linux 64-bit: QA_OS_LINUX64
 
 Mac OS X: QA_OS_MACOS
 Mac OS X 64-bit: QA_OS_MACOS64
 
 FreeBSD: QA_OS_FREEBSD
 FreeBSD 64-bit: QA_OS_FREEBSD64
*/

/* Dection of Microsoft Windows */
#if(defined(_WIN32) || defined(_WINDOWS))
#    define QA_OS_WIN32
#    if (defined(_WIN64) || defined(_M_X64))
#        define QA_OS_WIN64
#    endif
#endif

/* Detection of GNU/Linux */
#if(defined(__linux) || defined(__linux__))
#    define QA_OS_LINUX
#    ifdef __x86_64__
#        define QA_OS_LINUX64
#    endif
#endif

/* Detection of Apple OS X */
#if defined(__APPLE__)
#    define QA_OS_MACOS
#    ifdef __LP64__
#        define QA_OS_MACOS64
#    endif
#endif

/* Detection of FreeBSD */
#if defined(__FreeBSD__)
#    define QA_OS_FREEBSD
#    ifdef __x86_64__
#        define QA_OS_FREEBSD64
#    endif
#endif

#if defined(QA_OS_WIN64) || defined(QA_OS_LINUX64) || defined(QA_OS_MACOS64) || defined(QA_OS_FREEBSD64)
#    define QA_OS_ARCH64
#else
#    define QA_OS_ARCH32
#endif

#if defined(QA_OS_ARCH64)
#   define QA_POINTER_SIZE 8
#else
#   define QA_POINTER_SIZE 4
#endif

#define QA_HANDLE void*

/* Library defines for exporting symbols (needed for Windows) */
#ifdef QA_OS_WIN32
#   define QA_EXPORT __declspec(dllexport)
#   define QA_IMPORT __declspec(dllimport)
#   define QA_EXPORT_SYMBOLS_BEGIN
#   define QA_EXPORT_SYMBOLS_END
#else
#   define QA_EXPORT __attribute__((visibility("default")))
#   define QA_IMPORT
#if(defined(QA_CC_CLANG) || defined(QA_CC_GCC))
#   define QA_EXPORT_SYMBOLS_BEGIN _Pragma("GCC visibility push(default)")
#   define QA_EXPORT_SYMBOLS_END _Pragma("GCC visibility pop")
#else
#   define QA_EXPORT_SYMBOLS_BEGIN
#   define QA_EXPORT_SYMBOLS_END
#endif
#endif

#ifdef QA_STD_CPP
#   define QA_EXTERN_C_BEGIN extern "C" {
#   define QA_EXTERN_C_END }
}
#else
#   define QA_EXTERN_C_BEGIN
#   define QA_EXTERN_C_END
#endif

#endif

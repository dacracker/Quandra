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

#ifndef __QUANDRA_PLATFORM_IMPL_H__
#define __QUANDRA_PLATFORM_IMPL_H__

#include "qa_platform.h"

#pragma once

/*
                            WARNING!
        This file is part of the game engine's private API. It should
        _only_ be used by other parts of the engine itself.
 */

struct _qa_platform {
    int (*init)(void);
    void (*shutdown)(void);
    
    int (*exec)(void);
};

// This function must be implemented by platform plugins
extern int _qa_platform_init(struct _qa_platform *);

struct _qa_window_impl {
    QA_HANDLE (*create_window)(const char *title, int width, int height);
    void (*destroy_window)(QA_HANDLE window);
    
    void (*show_window)(QA_HANDLE window);
    void (*hide_window)(QA_HANDLE window);
};

extern int _qa_window_impl_init(struct _qa_window_impl *impl);

#endif

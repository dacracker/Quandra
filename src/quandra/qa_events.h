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

#ifndef __QUANDRA_EVENTS_H__
#define __QUANDRA_EVENTS_H__

#include "qa_common.h"

#pragma once

enum qa_event_type {
    QA_QUIT,
    
    QA_KEYUP,
    QA_KEYDOWN,
    
    QA_MOUSEMOTION,
    QA_MOUSEUP,
    QA_MOUSEDOWN
};

struct qa_quit_event {
    qa_uint32 type; // QA_QUIT
};

enum qa_key_state {
    QA_PRESSED,
    QA_RELEASED
};

struct qa_keyboard_event{
    qa_uint32 type; // QA_KEYUP or QA_KEYDOWN
    qa_uint32 timestamp;
    qa_key_state state; // QA_PRESSED or QA_RELEASED
    
};

union qa_event {
    qa_uint32 type;
    struct qa_quit_event quit;
    struct qa_keybord_event keyboard;
}

#endif

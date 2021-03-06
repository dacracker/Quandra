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

#ifndef __QUANDRA_WINDOW_H__
#define __QUANDRA_WINDOW_H__

#include "qa_common.h"

#pragma once

QA_EXTERN_C_BEGIN

struct qa_window;

/** Creates a new render window
  * Create one more more windows to present the content
  * of your game. The window is hidden by default.
  */
struct qa_window* QA_API qa_window_create(const qa_char* title, qa_int32 width, qa_int32 height);

/** Destroys a render window
  * Every window must be destroyed before the application quits
  */
void QA_API qa_window_destroy(struct qa_window *window);

/** Presents the window to the user */
void QA_API qa_window_show(struct qa_window *window);

/** Hides the window from the user */
void QA_API qa_window_hide(struct qa_window *window);

QA_EXTERN_C_END

#endif

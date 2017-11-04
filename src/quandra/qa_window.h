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

struct SDL_Window;
struct SDL_Renderer;

/** Creates a new render window */
struct SDL_Window* QA_API QWindow_Create(const char* title, int width, int height);

/** Destroys the render window */
void QA_API QWindow_Destroy(struct SDL_Window *window);

/** Displays the window on the screen */
void QA_API QWindow_Show(struct SDL_Window *window);

/** Hides the window */
void QA_API QWindow_Hide(struct SDL_Window *window);

/** Starts the message loop */
void QA_API QWindow_PumpEvents(struct SDL_Window *win);

/********************* Private API **********************/

/* Get the renderer */
struct SDL_Renderer* QWindow_GetRenderer(struct SDL_Window *win);

#endif

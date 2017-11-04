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

#include "qa_window.h"

#include <SDL.h>
#include <SDL_events.h>

QA_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
struct SDL_Window* QWindow_Create(const char* title, int width, int height)
{
    struct SDL_Window *win;
    win = SDL_CreateWindow(title,
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width,
                           height,
                           SDL_WINDOW_HIDDEN);
    
    if(win == 0){
        SDL_Log("QWindow_Create() - Failed to create window, error: %s", SDL_GetError());
    }
    
    return win;
}

/******************************************************************/
void QWindow_Destroy(struct SDL_Window *window)
{
    SDL_DestroyWindow(window);
}

/******************************************************************/
void QWindow_Show(struct SDL_Window *window)
{
    SDL_ShowWindow(window);
}

/******************************************************************/
void QWindow_Hide(struct SDL_Window *window)
{
    SDL_HideWindow(window);
}

/******************************************************************/
void QWindow_PumpEvents(struct SDL_Window *win)
{
    SDL_Log("QWindow_PumpEvents() - Starting message loop");
    
    union SDL_Event ev;
    SDL_bool quit = SDL_FALSE;
    
    while(quit != SDL_TRUE){
        if(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
                default:
                    break;
            }
        }
    }
    
    SDL_Log("QWindow_PumpEvents() - Message loop ended");
}

QA_EXPORT_SYMBOLS_END


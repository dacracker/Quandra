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

#ifndef __QUANDRA_GAMESTATE_H__
#define __QUANDRA_GAMESTATE_H__

#pragma once

union SDL_Event;
struct SDL_Renderer;

struct QGameState {
    void (*OnEnter)(struct QGameState *self);
    void (*OnExit)(struct QGameState *self);
    /*
    void (*OnKeyEvent)(struct QGameState *self, union SDL_Event *event);
    void (*OnMouseEvent)(struct QGameState *self, union SDL_Event *event);
    void (*OnMouseMove)(struct QGameState *self, union SDL_Event *event);
    
    void (*OnUpdate)(struct QGameState *self, union SDL_Event *event);
    void (*OnRender)(struct QGameState *self, struct SDL_Renderer *renderer);*/
};

#endif

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

#include "qa_application.h"

#include <SDL.h>

QA_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
int QApp_Init(void)
{
    SDL_Log("QApp_Init() - Starting Quandra Game Engine...");
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("QApp_Init() - Fatal Error: %s", SDL_GetError());
        return 1;
    }
    
    struct SDL_version version;
    SDL_GetVersion(&version);
    
    SDL_Log("QApp_Init() - Using SDL2 version: %d.%d.%d",
            version.major, version.minor, version.patch);
    
    // The screen saver will automatically be re-enabled when we call QApp_Quit()
    SDL_DisableScreenSaver();

    return 0;
}

/******************************************************************/
void QApp_Quit(void)
{
    SDL_Log("QApp_Quit() - Time to quit, bye!");
    SDL_Quit();
}

/******************************************************************/
void QA_API QApp_Sleep(int ms)
{
    SDL_Delay(ms);
}

QA_EXPORT_SYMBOLS_END

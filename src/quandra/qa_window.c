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
#include "qa_platform_impl.h"

#include <string.h>
#include <stdlib.h>

struct qa_window{
    struct _qa_window_impl impl;
    QA_HANDLE handle;
};

QA_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
struct qa_window* QA_API qa_window_create(const qa_char* title, qa_int32 width, qa_int32 height)
{
    struct qa_window *window = malloc(sizeof(struct qa_window));
    memset(window,0,sizeof(struct qa_window));
    
    if(_qa_window_impl_init(&window->impl) != 0) {
        free(window);
        return 0;
    }
    
    window->handle = (*window->impl.create_window)(title,width,height);
    
    if(window->handle == 0){
        free(window);
        return 0;
    }
    
    return window;
}

/******************************************************************/
void QA_API qa_window_destroy(struct qa_window *window)
{
    (*window->impl.destroy_window)(window->handle);
}

/******************************************************************/
void qa_window_show(struct qa_window *window)
{
    (*window->impl.show_window)(window);
}

/******************************************************************/
void qa_window_hide(struct qa_window *window)
{
    (*window->impl.hide_window)(window);
}

QA_EXPORT_SYMBOLS_END


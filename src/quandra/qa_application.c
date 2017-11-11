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
#include "qa_platform_impl.h"

#include <string.h>

struct QApp {
    struct _qa_platform platform;
} qapp;

QA_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
qa_int32 qapp_init(void)
{
    memset(&qapp,0,sizeof(struct QApp));
    
    if(_qa_platform_init(&qapp.platform) != 0)
        return 1;
    
    if((*qapp.platform.init)() != 0)
        return 1;
    
    return 0;
}

/******************************************************************/
void qapp_quit(void)
{
    (*qapp.platform.shutdown)();
    
    memset(&qapp,0,sizeof(struct QApp));
}

/******************************************************************/
qa_int32 qapp_exec(void)
{
    return (*qapp.platform.exec)();
}

QA_EXPORT_SYMBOLS_END

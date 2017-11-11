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

#include "qa_io.h"

#include <stdlib.h>
#include <stdarg.h>

#include <unicode/ustdio.h>
#include <unicode/uchar.h>

UChar test;

struct qa_file {
    UFILE *handle;
};

QA_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
void qa_printf(const qa_char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);
    u_vfprintf(u_get_stdout(),fmt,vargs);
    va_end(vargs);
}

/******************************************************************/
struct qa_file* qa_fopen(const qa_char *file_path, const qa_char *perm, const qa_char* encoding)
{
    struct qa_file *file = malloc(sizeof(struct qa_file));
    
    if(!file)
        return 0;
    
    // Default to UTF-8 if no specific encoding is specified
    const qa_char* enc = encoding == 0 ? u8"UTF-8" : encoding;
    
    file->handle = u_fopen(file_path,perm,0,enc);
    
    if(file->handle == 0){
        free(file);
        return 0;
    }
    
    return file;
}

/******************************************************************/
void qa_fclose(struct qa_file *file)
{
    u_fclose(file->handle);
    free(file);
}

/******************************************************************/
qa_int32 qa_fwrite(struct qa_file *file,  const qa_char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);
    qa_int32 result = u_vfprintf(file->handle,fmt,vargs);
    va_end(vargs);
    
    return result;
}

/******************************************************************/
void qa_fflush(struct qa_file *file)
{
    u_fflush(file->handle);
}

/******************************************************************/
bool qa_feof(struct qa_file *file)
{
    return u_feof(file->handle);
}

/******************************************************************/
void qa_frewind(struct qa_file *file)
{
    u_frewind(file->handle);
}

QA_EXPORT_SYMBOLS_END

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

#ifndef __QUANDRA_IO_H__
#define __QUANDRA_IO_H__

#include "qa_common.h"

#pragma once

/************************* STD I/O API ***************************/

void QA_API qa_printf(const qa_char* fmt, ...);

/************************* FILE API ******************************/

struct qa_file;

struct qa_file* QA_API qa_fopen(const qa_char *file_path, const qa_char *perm, const qa_char* encoding);
void QA_API qa_fclose(struct qa_file *file);

/** Writes a UTF-8 encoded string to the file
  * Returns the number of characters written to the file (not bytes)
  */
qa_int32 QA_API qa_fwrite(struct qa_file *file, const qa_char *fmt, ...);

/** Flushes the the write buffer to disk */
void QA_API qa_fflush(struct qa_file *file);

/** Returns true if the file pointer is a the end of the file */
bool QA_API qa_feof(struct qa_file *file);

/** Set the file pointer to point at the beginning of the file */
void QA_API qa_frewind(struct qa_file *file);

#endif

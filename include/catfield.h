/* ***************************** aCat ******************************** **
**
** @file catfield
** @description
**
** @author Copyright (C) 2023  Leo Turnell-Ritson
** @version 0.1
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA.
**
** ******************************************************************** */


#ifndef CATFIELD_H
#define CATFIELD_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "catsys.h"


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

typedef char* FieldType;
#define FIELDNATIVE  "native"


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode FieldCreate(MPI_Comm, Layout *, Field *);
extern CatErrorCode FieldDestroy(Field *);
extern CatErrorCode FieldSetType(Field, FieldType);
extern CatErrorCode FieldGetType(Field, FieldType *);
extern CatErrorCode FieldSetSizes(Field, CatInt, CatInt);

extern CatErrorCode FieldCreateNative(MPI_Comm, Layout *, Field *);

#endif

/* ******************************************************************** */

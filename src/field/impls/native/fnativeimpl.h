/* ***************************** aCat ******************************** **
**
** @file fnativeimpl
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


#ifndef FNATIVEIMPL_H
#define FNATIVEIMPL_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include <cat/private/fieldimpl.h>


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

typedef struct {
    CatScalar *array;
} _n_FieldNative;


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode FieldDestroyNative_Internal(Field);
extern CatErrorCode FieldCreateNative_Internal(Field);
extern CatErrorCode FieldGetArrayNative_Internal(Field, CatScalar **);
extern CatErrorCode FieldRestoreArrayNative_Internal(Field, CatScalar **);
extern CatErrorCode FieldGetSizeNative_Internal(Field, CatInt *);
extern CatErrorCode FieldGetInSizeNative_Internal(Field, CatInt *);


#endif

/* ******************************************************************** */

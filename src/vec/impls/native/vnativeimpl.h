/* ***************************** aCat ******************************** **
**
** @file vnativeimpl
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


#ifndef VNATIVEIMPL_H
#define VNATIVEIMPL_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include <cat/private/vecimpl.h>


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

typedef struct {
    CatScalar *array;
    CatInt     nghost;
    CatMPIInt  nsendranks;
    CatMPIInt  nrecvranks;
    CatMPIInt *sendranks;
    CatMPIInt *recvranks;
} _n_VecNative;

/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode VecDestroyNative_Internal(Vec);
extern CatErrorCode VecCreateNative_Internal(Vec);
extern CatErrorCode VecGetArrayNative_Internal(Vec, CatScalar **);
extern CatErrorCode VecRestoreArrayNative_Internal(Vec, CatScalar **);
extern CatErrorCode VecGetSizeNative_Internal(Vec, CatInt *);
extern CatErrorCode VecGetLocalSizeNative_Internal(Vec, CatInt *);

#endif

/* ******************************************************************** */

/* ***************************** aCat ******************************** **
**
** @file catimpl
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


#ifndef CATIMPL_H
#define CATIMPL_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "catsys.h"


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

#define CatHeaderCreate(h, comm, dest) \
  CatHeaderCreate_Private(CatNew(&(h)), \
                          (CatObject *)&(h), \
                          (comm), \
                          (CatObjectDestroyFunction)(dest))

#define CatHeaderDestroy(h) CatHeaderDestroy_Private((CatObject *)h)


/* ******************************************************************** */
/* ************************** public data ***************************** */
/* ******************************************************************** */

typedef CatErrorCode (*CatObjectDestroyFunction)(CatObject *);

typedef struct CatOps {
    CatErrorCode (*destroy)(CatObject *);
} CatOps;

typedef struct _p_CatObject {
    CatOps      bops[1];
    CatObjectId id;
} _p_CatObject;


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode CatHeaderCreate_Private(CatErrorCode,
                                            CatObject *,
                                            MPI_Comm,
                                            CatObjectDestroyFunction);

extern CatErrorCode CatHeaderDestroy_Private(CatObject *h);


#endif

/* ******************************************************************** */

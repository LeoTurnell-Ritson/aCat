/* ***************************** aCat ******************************** **
**
** @file vecimpl
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


#ifndef VECIMPL_H
#define VECIMPL_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "catvec.h"
#include "cat/private/catimpl.h"


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */



/* ******************************************************************** */
/* ************************** public data ***************************** */
/* ******************************************************************** */

struct _p_CatLayout {
    MPI_Comm  comm;
    CatInt    n, N;           /* local, global vector size */
    CatInt    lstart, lend;   /* local start, local end + 1 */
};

struct _n_VecOps {
    CatErrorCode (*destroy)(Vec);    /* Implementation specific data destruction. */
    CatErrorCode (*create)(Vec);     /* Implementation specific data creation. */
    CatErrorCode (*getarray)(Vec, CatScalar **);
    CatErrorCode (*restorearray)(Vec, CatScalar **);
    CatErrorCode (*getsize)(Vec, CatInt *);
    CatErrorCode (*getlocalsize)(Vec, CatInt *);
};

struct _p_Vec {
    _p_CatObject      hdr;
    struct _n_VecOps  ops[1];
    CatLayout         map;
    void             *data; /* Implementation specific data. */
};


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */


#endif

/* ******************************************************************** */

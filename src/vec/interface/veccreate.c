/* ***************************** aCat ******************************** **
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


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "cat/private/vecimpl.h"


/* ******************************************************************** */
/* ********************** private functions *************************** */
/* ******************************************************************** */

static struct _n_VecOps NullOps =
{
    CatDesignatedInitializer(destroy,       NULL),
    CatDesignatedInitializer(create,        NULL),
    CatDesignatedInitializer(getarray,      NULL),
    CatDesignatedInitializer(restorearray,  NULL),
    CatDesignatedInitializer(getsize,       NULL),
    CatDesignatedInitializer(getlocalsize,  NULL)
};


/* ******************************************************************** */
/* ********************** function definitions ************************ */
/* ******************************************************************** */

CatErrorCode VecCreate(MPI_Comm   comm,
                       CatLayout *map,
                       Vec       *vec)
{
    Vec v;

    CatFunctionBegin;
    CatCall(CatHeaderCreate(v, comm, "Vec"));
    CatSetTypeOps(v, NullOps);
    v->map  = *map;
    v->data = NULL;
    *vec    = NULL;
    *vec    = v;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */

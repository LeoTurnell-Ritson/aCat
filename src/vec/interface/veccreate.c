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
    CatDesignatedInitializer(destroy, NULL),
    CatDesignatedInitializer(create,  NULL)
};

static CatErrorCode LayoutCreate_Static(MPI_Comm comm,
                                        CatLayout *map)
{
    CatFunctionBegin;
    CatCall(CatNew(map));
    (*map)->comm = comm;
    (*map)->n = -1;
    (*map)->N = -1;
    (*map)->lstart = 0;
    (*map)->lend   = 0;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */
/* ********************** function definitions ************************ */
/* ******************************************************************** */

CatErrorCode VecCreate(MPI_Comm  comm,
                       Vec      *vec)
{
    Vec v;

    CatFunctionBegin;
    *vec = NULL;
    CatCall(CatHeaderCreate(v, comm, "Vec"));
    CatCall(LayoutCreate_Static(comm, &v->map));
    CatSetTypeOps(v, NullOps);
    v->data = NULL;
    *vec = v;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */

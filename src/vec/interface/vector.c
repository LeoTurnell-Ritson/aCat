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

static CatErrorCode LayoutDestroy_Static(CatLayout *map)
{
    CatFunctionBegin;
    CatCall(CatFree((*map)));
    *map = NULL;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */
/* ********************** functions definitions *********************** */
/* ******************************************************************** */

CatErrorCode VecDestroy(Vec *v)
{
    CatFunctionBegin;
    CatTryTypeMethod(*v, destroy);
    CatCall(LayoutDestroy_Static(&(*v)->map));
    CatCall(CatHeaderDestroy(v));
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode VecSetSizes(Vec v,
                         CatInt n,
                         CatInt N)
{
    CatFunctionBegin;
    v->map->n = n;     /* TODO: Needs some N >= n sanity checking. */
    v->map->N = N;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */
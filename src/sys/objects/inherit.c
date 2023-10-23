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

#include "cat/private/catimpl.h"


/* ******************************************************************** */
/* ********************** Static functions ********** ***************** */
/* ******************************************************************** */


/* ******************************************************************** */
/* ********************** function definitions *********************** */
/* ******************************************************************** */

CatErrorCode CatHeaderCreate_Private(CatErrorCode err,
                                     CatObject *h,
                                     MPI_Comm comm,
                                     CatObjectDestroyFunction destroy)
{
    CatNoUnusedWarn(comm);

    if (err)
        CatFunctionReturn(err);
    CatFunctionBegin;
    (*h)->bops->destroy = destroy;
    (*h)->id = 0;                   /*TODO: Sort an object id tracker.*/
    CatFunctionReturn(CAT_SUCCESS);
}


CatErrorCode CatHeaderDestroy_Private(CatObject *h)
{
    CatFunctionBegin;
    CatCall(CatFree(*h));
    CatFunctionReturn(CAT_SUCCESS);
}

/* ******************************************************************** */

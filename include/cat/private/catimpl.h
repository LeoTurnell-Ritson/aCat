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

#define CatHeaderCreate(h, comm, class, dest) \
    CatHeaderCreate_Private(CatNew(&(h)), \
                            (CatObject *)&(h), \
                            (comm), \
                            (class))

#define CatHeaderDestroy(h) CatHeaderDestroy_Private((CatObject *)h)

#define CatTryTypeMethod(obj, ...) \
    do { \
        if ((obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused)) != NULL) \
        { \
            CatErrorCode ierr__; \
            ierr__ = (*(obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused))) \
                (obj CAT_REST_ARG(__VA_ARGS__)); \
            CatCall(ierr__); \
        } \
    } while (0)

#define CatUseTypeMethod(obj, ...)  \
    do { \
        if ((obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused)) != NULL) \
        { \
            CatErrorCode ierr__; \
            ierr__ = (*(obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused))) \
                (obj CAT_REST_ARG(__VA_ARGS__)); \
            CatCall(ierr__); \
        } \
        else  \
        { \
            CatCall(CAT_ERR_OPSNOTSET);  \
        } \
    } while (0)


/* ******************************************************************** */
/* ************************** public data ***************************** */
/* ******************************************************************** */

typedef struct _p_CatObject {
    CatObjectId  id;
    MPI_Comm     comm;
    char        *class;
    char        *type;
} _p_CatObject;


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode CatHeaderCreate_Private(CatErrorCode,
                                            CatObject *,
                                            MPI_Comm,
                                            char *);

extern CatErrorCode CatHeaderDestroy_Private(CatObject *h);


#endif

/* ******************************************************************** */

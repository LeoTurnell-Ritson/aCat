/* ***************************** aCat ******************************** **
**
** @file catsys
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


#ifndef CATSYS_H
#define CATSYS_H


/* ******************************************************************** */
/* ********************** include standard files ********************** */
/* ******************************************************************** */

#include <stdlib.h>


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include <cattypes.h>
#include <caterror.h>
#include <catmacros.h>


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

#define CatNew(h) CatMalloc(__FILE__, __FUNC__, __LINE__, \
                            sizeof (**(h)), (void*)(h))


#define CatFree(h) ((CatErrorCode)((free(h)),  \
                                   (h = NULL, CAT_SUCCESS)))

/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode CatInitialise(int *, char ***);
extern CatErrorCode CatFinalise(void);
extern CatErrorCode CatMalloc(const char *, const char *, const int,
                              const size_t, void **);


#endif


/* ******************************************************************** */

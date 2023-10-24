/* ***************************** aCat ******************************** **
**
** @file cattypes
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


#ifndef CATTYPES_H
#define CATTYPES_H


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

typedef enum CatErrorCode {
    CAT_SUCCESS = 0,
    CAT_FAILURE = 1,        /* Do not use. */
    CAT_ERR_OPSNOTSET = 55  /* Ops method of the object has not been set (is NULL). */
} CatErrorCode;

typedef enum CatBool {
    CAT_FALSE = 0,
    CAT_TRUE = 1
} CatBool;


/* ******************************************************************** */
/* ************************** public data ***************************** */
/* ******************************************************************** */

typedef short int CatFlag;
typedef long      CatInt;
typedef double    CatScalar;
typedef int       CatObjectId;
typedef int       CatMPIInt;

typedef struct _p_CatObject *CatObject;

#endif


/* ******************************************************************** */

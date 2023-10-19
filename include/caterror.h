/* ***************************** aCat ******************************** **
**
** @file caterror
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


#ifndef CATERROR_H
#define CATERROR_H


/* ******************************************************************** */
/* ********************** include standard files ********************** */
/* ******************************************************************** */

#include <stdio.h>
#include <mpi.h>


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "catmacros.h"
#include "cattypes.h"


/* ******************************************************************** */
/* ************************* private constants ************************ */
/* ******************************************************************** */

#define private_StackPush(stack__, file__, func__, line__) \
    do { \
        if (stack__.currsize < CAT_STACKSIZE) { \
            stack__.file[stack__.currsize] = file__; \
            stack__.function[stack__.currsize] = func__; \
            stack__.line[stack__.currsize] = line__; \
        } \
        ++stack__.currsize; \
    } while (0) \


#define private_StackPop(stack__) \
    do { \
        --stack__.currsize; \
        stack__.file[stack__.currsize] = NULL; \
        stack__.function[stack__.currsize] = NULL; \
        stack__.line[stack__.currsize] = 0; \
    } while (0) \

#define private_StackUpdateLine(stack__, line__, func__) \
    do { \
        if (stack__.currsize > 0 && stack__.function[stack__.currsize - 1] == func__) \
            stack__.line[stack__.currsize - 1] = line__; \
    } while (0) \


#define private_Call(...) \
    do { \
        CatStackUpdateLine; \
        CatErrorCode err = __VA_ARGS__ ; \
        if (CatUnlikely(err != CAT_SUCCESS)) CatError(__CATSTACK__, err);   \
    } while(0) \


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */


#define CatStackPush(func) private_StackPush(__CATSTACK__, __FILE__, func, __LINE__)
#define CatStackPop        private_StackPop(__CATSTACK__)
#define CatStackUpdateLine private_StackUpdateLine(__CATSTACK__, __LINE__, __FUNC__)
#define CatCall(...)       private_Call(__VA_ARGS__)

#define CatFunctionBegin        CatStackPush(__FUNC__)
#define CatFunctionReturn(...)  CatStackPop; return __VA_ARGS__

#define CAT_STACKSIZE 64

typedef struct CatStack {
    const char  *function[CAT_STACKSIZE];
    const char  *file[CAT_STACKSIZE];
    int         line[CAT_STACKSIZE];
    int         currsize;
} CatStack;


/* ******************************************************************** */
/* ************************** public data ***************************** */
/* ******************************************************************** */

extern CatStack  __CATSTACK__;
extern int       CatRank;
extern int       CatSize;


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode CatError(const CatStack, const CatErrorCode);


#endif

/* ******************************************************************** */

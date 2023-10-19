/* ***************************** aCat ******************************** **
**
** @file catmacro
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


#ifndef CATMACROS_H
#define CATMACROS_H


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

#define __FUNC__  __func__
/*#define NULL      ((void *)0)*/

#define CatUnlikely(cond)   __builtin_expect(!!(cond), 0)
#define CatLikely(cond)     __builtin_expect(!!(cond), 1)
#define CatNoUnusedWarn(x)  (void)(x)


#endif

/* ******************************************************************** */

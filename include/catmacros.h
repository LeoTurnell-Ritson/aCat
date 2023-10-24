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

#define CatUnlikely(cond)                   __builtin_expect(!!(cond), 0)
#define CatLikely(cond)                     __builtin_expect(!!(cond), 1)
#define CatNoUnusedWarn(x)                  (void)(x)
#define CatDesignatedInitializer(name, ...) .name = __VA_ARGS__

#define CAT_FIRST_ARG_HELPER(N, ...)                                                                N
#define CAT_FIRST_ARG(args)                                                                         CAT_FIRST_ARG_HELPER args
#define CAT_SELECT_16TH(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, ...) a16
#define CAT_NUM(...)                                                                                CAT_SELECT_16TH(__VA_ARGS__, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE, ONE, throwaway)
#define CAT_REST_HELPER_TWOORMORE(first, ...)                                                       , __VA_ARGS__
#define CAT_REST_HELPER_ONE(first)
#define CAT_REST_HELPER2(qty, ...)                                                                  CAT_REST_HELPER_##qty(__VA_ARGS__)
#define CAT_REST_HELPER(qty, ...)                                                                   CAT_REST_HELPER2(qty, __VA_ARGS__)
#define CAT_REST_ARG(...)                                                                           CAT_REST_HELPER(CAT_NUM(__VA_ARGS__), __VA_ARGS__)


#endif

/* ******************************************************************** */

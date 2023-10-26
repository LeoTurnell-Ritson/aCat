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

#include <../src/field/impls/native/fnativeimpl.h>


/* ******************************************************************** */
/* ********************** functions definitions *********************** */
/* ******************************************************************** */


CatErrorCode FieldDestroyNative_Internal(Field f)
{
    CatFunctionBegin;
    CatCall(CatFree(f->data));
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode FieldCreateNative_Internal(Field f)
{
    _n_FieldNative *s;

    CatFunctionBegin;
    CatCall(CatNew(&s));
    f->data = (void *)s;
    s->array = NULL;
    f->ops->create = NULL;    /* Stops create method from being called? */
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode FieldGetArrayNative_Internal(Field f,
                                          CatScalar **a)
{
    CatFunctionBegin;
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode FieldRestoreArrayNative_Internal(Field f,
                                              CatScalar **a)
{
    CatFunctionBegin;
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode FieldGetSizeNative_Internal(Field f,
                                         CatInt *n)
{
    CatFunctionBegin;
    CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode FieldGetInSizeNative_Internal(Field f,
                                              CatInt *ln)
{
    CatFunctionBegin;
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */

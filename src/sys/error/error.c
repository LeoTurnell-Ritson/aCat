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

#include "caterror.h"

/* ******************************************************************** */
/* ************************ global variables ************************** */
/* ******************************************************************** */

CatStack  __CATSTACK__;
int       CatRank;
int       CatSize;


/* ******************************************************************** */
/* ********************** private functions *************************** */
/* ******************************************************************** */

static void ErrorDump_Static(const CatErrorCode err, FILE *out)
{
    const char * msg = "CAT FATAL ERROR: errorcode";

    fprintf(out, "[%d]%s (%d)\n", CatRank, msg, err);
}

static void StackDump_Static(const CatStack stack, FILE *out)
{
    int i;
    const char * msg = "CAT STACK DUMP:";

    fprintf(out, "[%d]%s ", CatRank, msg);
    for (i=0; i < stack.currsize; i++)
    {
        fprintf(out, "%s:", stack.file[i]);
        fprintf(out, "%s:", stack.function[i]);
        fprintf(out, "%d\t", stack.line[i]);
    }
    fprintf(out, "\n");
}


/* ******************************************************************** */
/* ********************** functions definitions *********************** */
/* ******************************************************************** */

void CatError(const CatStack stack, const CatErrorCode err)
{
    ErrorDump_Static(err, stderr);
    StackDump_Static(stack, stderr);
    MPI_Abort(MPI_COMM_WORLD, err);
}


/* ******************************************************************** */

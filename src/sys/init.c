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

#include "catsys.h"


/* ******************************************************************** */
/* ********************** functions definitions *********************** */
/* ******************************************************************** */

CatErrorCode CatInitialise(int * argc, char ***argv)
{
    CatFunctionBegin;
    /*
     * TODO: impliment CatCatMPI(...)
     * --> CatCallMPI(MPI_init(argc, argv));
     */
    MPI_Init(argc, argv);
    MPI_Comm_size(MPI_COMM_WORLD, &CatSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &CatRank);
    CatFunctionReturn(CAT_SUCCESS);
}


/* ******************************************************************** */

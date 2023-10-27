/* ***************************** aCat ******************************** **
**
** @file catdomain
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


#ifndef CATDOMAIN_H
#define CATDOMAIN_H


/* ******************************************************************** */
/* ************************** include files *************************** */
/* ******************************************************************** */

#include "catsys.h"


/* ******************************************************************** */
/* **************************** constants ***************************** */
/* ******************************************************************** */

typedef char* DomainType;
#define  DOMAINDISTR "distr"    /* Distributed Cartesian array. */
#define  DOMAINSTAGG "stagg"  /* Staggered set of (1+dimensions) distributed arrays. */
#define  DOMAINSWARM "swarm" /* Swarm array, embedded in a distributed array. */


/* ******************************************************************** */
/* *********************** public functions *************************** */
/* ******************************************************************** */

extern CatErrorCode DomainCreate(MPI_Comm,  Domain *);
extern CatErrorCode DomainDestroy(Domain *);
extern CatErrorCode DomainSetType(Domain, DomainType);
extern CatErrorCode DomainGetType(Domain, DomainType *);


#endif

/* ******************************************************************** */

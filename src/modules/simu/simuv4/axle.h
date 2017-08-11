/***************************************************************************

    file                 : axle.h
    created              : Sun Mar 19 00:05:17 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: axle.h 2917 2010-10-17 19:03:40Z pouillot $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


 
#ifndef _AXLE_H__
#define _AXLE_H__

#include "differential.h"

typedef struct
{
    float xpos;

    tSuspension arbSusp;	/* anti-roll bar */
    tSuspension heaveSusp;  /* heave/3rd/central spring */
    float	wheight0;

    /* dynamic */
    float	force[2]; /* right and left */

    float	I;	/* including differential inertia but not wheels */
} tAxle;


#endif /* _AXLE_H__ */ 




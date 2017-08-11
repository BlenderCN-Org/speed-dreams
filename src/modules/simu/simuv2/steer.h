/***************************************************************************

    file                 : steer.h
    created              : Sun Mar 19 00:08:32 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id$

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _STEER_H_
#define _STEER_H_

typedef struct
{
    float	steerLock;	/* in rad */
    float	maxSpeed;	/* in rad/s */
    float	steer;		/* current steer value */
    
} tSteer;




#endif /* _STEER_H_ */ 




/***************************************************************************

    file        : Vec3d.h
    created     : 9 Apr 2006
    copyright   : (C) 2006 Tim Foden

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _VEC3D_H_
#define _VEC3D_H_

#include <v3_t.h>
#include <tgf.h>

#include "Vec2d.h"

class Vec3d : public v3t<double>
{
public:
	Vec3d() {}
	Vec3d( const v3t<double>& v ) : v3t<double>(v) {}
	Vec3d( double x, double y, double z ) : v3t<double>(x, y, z) {};
	Vec3d( const glm::vec3& v ) : v3t<double>(v.x, v.y, v.z) {}

	Vec3d&	operator=( const v3t<double>& v )
	{
		v3t<double>::operator=(v);
		return *this;
	}

	glm::dvec2	GetXY() const { return glm::dvec2(x, y); }
};

#endif

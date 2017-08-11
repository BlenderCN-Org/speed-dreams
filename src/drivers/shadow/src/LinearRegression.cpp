/***************************************************************************

    file        : LinearRegression.cpp
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

// LinearRegression.cpp: implementation of the LinearRegression class.
//
//////////////////////////////////////////////////////////////////////

#include <robottools.h>

#include "LinearRegression.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LinearRegression::LinearRegression()
:	m_n(0),
	m_sumX(0),
	m_sumY(0),
	m_sumXY(0),
	m_sumXX(0),
	m_sumYY(0)
{
}

LinearRegression::~LinearRegression()
{
}

void LinearRegression::Clear()
{
	m_n = 0;
	m_sumX = 0;
	m_sumY = 0;
	m_sumXY = 0;
	m_sumXX = 0;
	m_sumYY = 0;
}

void LinearRegression::Sample( double X, double Y )
{
	m_n++;
	m_sumX  += X;
	m_sumY  += Y;
	m_sumXY += X * Y;
	m_sumXX += X * X;
	m_sumYY += Y * Y;
}

void LinearRegression::Sample( const glm::dvec2& p )
{
	Sample( p.x, p.y );
}

// vertical distance measure.
double LinearRegression::CalcY( double X ) const
{
	double	Xbar = m_sumX / m_n;
	double	Ybar = m_sumY / m_n;

	double	a = (m_sumXY + Xbar * m_sumY + m_sumX * Ybar + Xbar * Ybar) /
				(m_sumXX + Xbar * Xbar + 2 * m_sumX * Xbar);
				
	double	b = Ybar - a * Xbar;
//	GfOut( "a %g   b %g\n", a, b );

	return a * X + b;
}

// perpendicular distance measure.
void LinearRegression::CalcLine( glm::dvec2& p, glm::dvec2& v ) const
{
	p = glm::dvec2(m_sumX / m_n, m_sumY / m_n);

	// a = x - p.x, b = y - p.y
	double	sumAA = m_sumXX - 2 * p.x * m_sumX + m_n * p.x * p.x;
	double	sumBB = m_sumYY - 2 * p.y * m_sumY + m_n * p.y * p.y;
	double	sumAB = m_sumXY - p.y * m_sumX - p.x * m_sumY + m_n * p.x * p.y;

	double	ang = atan2(2 * sumAB, sumAA - sumBB) / 2;
	v = glm::dvec2(cos(ang), sin(ang));

//	GfOut( "x %g  y %g  a %g\n", p.x, p.y, ang );
}

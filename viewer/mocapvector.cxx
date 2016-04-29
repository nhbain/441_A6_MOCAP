#include <cmath>
#include <cstdio>
#include "transform.h"
#include "types.h"

#include "mocapvector.h"

//#include "mathclass.h"

mocapvector operator-( mocapvector const& a, mocapvector const& b )
{
    mocapvector c;

    c.p[0] = a.p[0] - b.p[0];
    c.p[1] = a.p[1] - b.p[1];
    c.p[2] = a.p[2] - b.p[2];

    return c;
}

mocapvector operator+( mocapvector const& a, mocapvector const& b )
{
    mocapvector c;

    c.p[0] = a.p[0] + b.p[0];
    c.p[1] = a.p[1] + b.p[1];
    c.p[2] = a.p[2] + b.p[2];

    return c;
}

mocapvector operator/( mocapvector const& a, float b )
{
    mocapvector c;

    c.p[0] = a.p[0] / b;
    c.p[1] = a.p[1] / b;
    c.p[2] = a.p[2] / b;

    return c;
}

//multip
mocapvector operator*( mocapvector const& a, float b )
{
    mocapvector c;

    c.p[0] = a.p[0] * b;
    c.p[1] = a.p[1] * b;
    c.p[2] = a.p[2] * b;

    return c;
}


//cross prodact
mocapvector operator*( mocapvector const& a, mocapvector const& b )
{
    mocapvector c;

    c.p[0] = a.p[1]*b.p[2] - a.p[2]*b.p[1];
    c.p[1] = a.p[2]*b.p[0] - a.p[0]*b.p[2];
    c.p[2] = a.p[0]*b.p[1] - a.p[1]*b.p[0];

    return c;
}

//dot prodact
float operator%( mocapvector const& a, mocapvector const& b )
{
    return ( a.p[0]*b.p[0] + a.p[1]*b.p[1] + a.p[2]*b.p[2] );
}


mocapvector
interpolate( float t, mocapvector const& a, mocapvector const& b )
{
	return a*(1.0-t) + b*t;
}

float len( mocapvector const& v )
{
    return sqrt( v.p[0]*v.p[0] + v.p[1]*v.p[1] + v.p[2]*v.p[2] );
}

float
mocapvector::length() const
{
    return sqrt( p[0]*p[0] + p[1]*p[1] + p[2]*p[2] );
}


float angle( mocapvector const& a, mocapvector const& b )
{
    return acos( (a%b)/(len(a)*len(b)) );
}



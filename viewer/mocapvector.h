/*
	skeleton.h

	Definition of the skeleton. 

    Written by  Jehee Lee
*/

#ifndef _VECTOR_H
#define _VECTOR_H


class mocapvector
{
    // negation
    friend mocapvector    operator-( mocapvector const& );

    // addtion
    friend mocapvector    operator+( mocapvector const&, mocapvector const& );

    // subtraction
    friend mocapvector    operator-( mocapvector const&, mocapvector const& );

    // dot product
    friend float    operator%( mocapvector const&, mocapvector const& );

    // cross product
    friend mocapvector    operator*( mocapvector const&, mocapvector const& );

    // scalar Multiplication
    friend mocapvector    operator*( mocapvector const&, float );

    // scalar Division
    friend mocapvector    operator/( mocapvector const&, float );


    friend float    len( mocapvector const& );
    friend mocapvector	normalize( mocapvector const& );

	friend mocapvector       interpolate( float, mocapvector const&, mocapvector const& );

    friend float       angle( mocapvector const&, mocapvector const& );

  // member functions
  public:
    // constructors
    mocapvector() {}
    mocapvector( float x, float y, float z ) { p[0]=x; p[1]=y; p[2]=z; }
    mocapvector( float a[3] ) { p[0]=a[0]; p[1]=a[1]; p[2]=a[2]; }
	~mocapvector() {};

    // inquiry functions
    float& operator[](int i) { return p[i];}

    float x() const { return p[0]; };
    float y() const { return p[1]; };
    float z() const { return p[2]; };
    void   getValue( float d[3] ) { d[0]=p[0]; d[1]=p[1]; d[2]=p[2]; }
    void   setValue( float d[3] ) { p[0]=d[0]; p[1]=d[1]; p[2]=d[2]; }

	float getValue( int n ) const { return p[n]; }
	mocapvector setValue( float x, float y, float z )
								   { p[0]=x, p[1]=y, p[2]=z; return *this; }
	float setValue( int n, float x )
								   { return p[n]=x; }

	float length() const;

    // change functions
    void set_x( float x ) { p[0]=x; };
    void set_y( float x ) { p[1]=x; };
    void set_z( float x ) { p[2]=x; };

	//data members
    float p[3]; //X, Y, Z components of the mocapvector
};


#endif

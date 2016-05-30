#pragma once
#include "stdafx.h"
#include "Transform.h"
#include <math.h>

Mat T;
std::vector< Mat > matrices(0);

Mat3D T3D;

void times( Mat a, Mat b, Mat &c )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
		{
			float skalaar = 0;
			for ( int k = 0; k < M; k++ )
				skalaar += a[i][k] * b[k][j];
			c[i][j] = skalaar;
		}
}

void timesMatVec( Mat a, Vec b, Vec &c )
{
	for ( int i = 0; i < M; i++ )
	{
		float skalaar = 0;
		for ( int j = 0; j < M; j++ )
			skalaar += a[i][j] * b[j];
		c[i] = skalaar;
	}
}

void set( Mat a, Mat &b )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			b[i][j] = a[i][j];
}

void point2vec( TPoint a, Vec &b )
{
	b[0] = a.x;
	b[1] = a.y;
	b[2] = 1;
}

void vec2point( Vec a, TPoint &b )
{
	b.x = ( (float) a[0] ) / a[2];
	b.y = ( (float) a[1] ) / a[2];
}

void makeHomogenVec( float x, float y, Vec &c )
{
	c[0] = x;
	c[1] = y;
	c[2] = 1;
}

void unit( Mat &a )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			if ( i == j )
				a[i][j] = 1;
			else
				a[i][j] = 0;
}

void move( float t_x, float t_y, Mat &c )
{
	unit(c);
	c[0][M - 1] = t_x;
	c[1][M - 1] = t_y;
}

void rotate( float centre_x, float centre_y, float phi, Mat &c )
{
	unit(c);

	c[0][0] = cos(phi);
	c[0][1] = -sin(phi);
	c[0][2] = centre_x * ( 1.0 - cos(phi) ) + centre_y * sin(phi);

	c[1][0] = sin(phi);
	c[1][1] = cos(phi);
	c[1][2] = centre_y * ( 1.0 - cos(phi) ) - centre_x * sin(phi);
}

void rotate( float phi, Mat &c )
{
	unit(c);

	c[0][0] = cos(phi);
	c[0][1] = -sin(phi);

	c[1][0] = sin(phi);
	c[1][1] = cos(phi);
}

void scale( float s_x, float s_y, Mat &c )
{
	unit(c);

	c[0][0] = s_x;
	c[1][1] = s_y;
}

void reflectVertical( Mat &a )
{
	unit(a);

	a[0][0] = -1;
}

void reflectHorizontal( Mat &a )
{
	unit(a);

	a[1][1] = -1;
}

void frame( float v_x, float v_y, float v_cx, float v_cy, 	float w_x, float w_y, float w_cx, float w_cy, 	Mat &c ){	Mat R, T1;	move( -v_cx, -v_cy, c );	scale( w_x / v_x, w_y / v_y, R );	times( R, c, T1 );	set( T1, c );	reflectHorizontal( R );
	times( R, c, T1 );
	set( T1, c );		move( w_cx, w_cy, R );	times( R, c, T1 );	set( T1, c );}

void times( Mat3D a, Mat3D b, Mat3D &c )
{
	unit(c);

	for( int i = 0; i < M3D; i++ )
		for( int j = 0; j < M3D; j++ )
		{
			float skalaar = 0;
			for(int k = 0; k < M3D; k++)
				skalaar += a[i][k] * b[k][j];
			c[i][j] = skalaar;
		}
}

void timesMatVec( Mat3D a, Vec3D b, Vec3D &c )
{
	for( int i = 0; i < M3D; i++ )
	{
		float skalaar = 0;
		for( int j = 0; j < M3D; j++ )
			skalaar += a[i][j] * b[j];
		c[i] = skalaar;
	}
}

void set( Mat3D a, Mat3D &b )
{
	for( int i = 0; i < M3D; i++ )
		for ( int j = 0; j < M3D; j++ )
			b[i][j] = a[i][j];
}

void point2vec( Point3D a, Vec3D &b )
{
	b[0] = a.x; 
	b[1] = a.y; 
	b[2] = a.z;
	b[3] = 1;
}

void vec2point( Vec3D a, Point3D &b )
{
	b.x = ( (float) a[0] ) / a[3];
	b.y = ( (float) a[1] ) / a[3];
	b.z = ( (float) a[2] ) / a[3];
}

void makeHomogenVec( float x, float y, float z, Vec3D &c )
{
	c[0] = x; 
	c[1] = y; 
	c[2] = z;
	c[3] = 1;
}


void unit( Mat3D &a )
{
	for ( int i = 0; i < M3D; i++ )
		for ( int j = 0; j < M3D; j++ )
		{
				if ( i == j)
					a[i][j] = 1;
				else
					a[i][j] = 0;
		}
}

void move( float t_x, float t_y, float t_z, Mat3D &c )
{
	unit(c);

	c[0][M3D - 1] = t_x;
	c[1][M3D - 1] = t_y;
	c[2][M3D - 1] = t_z;
}

void rotate( Point3D n, float phi, Mat3D &c )
{
	unit(c);

	float koef;
	Mat3D M1, M2, M3, R;

	unit(M1);
	unit(M2);
	unit(M3);

	M2[0][0] = 0;		M2[0][1] = -n.z;	M2[0][2] = n.y;	
	M2[1][0] = n.z;		M2[1][1] = 0;		M2[1][2] = -n.x;
	M2[2][0] = -n.y;	M2[2][1] = n.x;		M2[2][2] = 0;	

	koef = sin(phi);
	mult( M2, koef, R );
	sum( M1, R, M2 );

	M3[0][0] = n.x * n.x - 1;	M3[0][1] = n.x * n.y;		M3[0][2] = n.x * n.z;
	M3[1][0] = n.x * n.y;		M3[1][1] = n.y * n.y - 1;	M3[1][2] = n.y * n.z;
	M3[2][0] = n.x * n.z;		M3[2][1] = n.y * n.z;		M3[2][2] = n.z * n.z - 1;

	koef = 1 - cos(phi);
	mult( M3, koef, R );
	sum( M2, R, M3 );

	M3[3][3] = 1;
	set( M3, c );
}

void scale( float s_x, float s_y, float s_z, Mat3D &c )
{
	unit(c);

	c[0][0] = s_x;
	c[1][1] = s_y;
	c[1][2] = s_z;
}

void lookAt( Point3D eye, Point3D center, Point3D up, Mat3D &c )
{
	unit(c);

	Vec3D e_s1, e_s2, e_s3;

	calcDirVects( eye, center, up, e_s1, e_s2, e_s3 );

	Mat3D R1, R2;

	unit(R1);
	unit(R2);

	move( -eye.x, -eye.y, -eye.z, R1 );

	R2[0][0] = e_s1[0];	R2[0][1] = e_s1[1];	R2[0][2] = e_s1[2];
	R2[1][0] = e_s2[0];	R2[1][1] = e_s2[1];	R2[1][2] = e_s2[2];
	R2[2][0] = e_s3[0];	R2[2][1] = e_s3[1];	R2[2][2] = e_s3[2];

	times(R2, R1, c);
}

void ortho( float v_x, float v_y, float near, float far, Mat3D &c )
{
	unit(c);

	c[0][0] = 2.0 / v_x;
	c[1][1] = 2.0 / v_y;
	c[2][2] = 2.0 / ( far - near );
	c[2][3] = ( far + near ) / ( far - near );
}

void frustrum( float v_x, float v_y, float near, float far, Mat3D &c )
{
	unit(c);

	c[0][0] = near * 2.0 / v_x;
	c[1][1] = near * 2.0 / v_y;
	c[2][2] = ( far + near ) / ( far - near );
	c[2][3] = ( 2.0 * far * near ) / ( far - near );
	c[3][2] = -1.0;
	c[3][3] = 0;
}

void perspective( float fovy, float aspect, float near, float far, Mat3D &c )
{
	unit(c);

	c[0][0] = ( 1.0 / aspect ) * ( 1.0 / tan( fovy / 2.0 ) );
	c[1][1] = 1.0 / tan( fovy / 2.0 );
	c[2][2] = ( far + near ) / ( far - near );
	c[2][3] = ( 2.0 * far * near ) / ( far - near );
	c[3][2] = -1.0;
	c[3][3] = 0;
}

void set( Point3D a, TPoint &b )
{
	b.x = a.x;
	b.y = a.y;
}

void calcDirVects( Point3D eye, Point3D center, Point3D up, Vec3D &a, Vec3D &b, Vec3D &c )
{
	Vec3D s, p, u;

	point2vec( eye, s );
	point2vec( center, p );
	point2vec( up, u );

	normalize(u);

	Vec3D a_s, b_s, c_s, temp;

	mult( p, -1, temp );
	sum( s, temp, c_s );
	normalize( c_s );

	multVec( u, c_s, a_s );
	normalize( a_s );

	multVec( c_s, a_s, b_s );
	normalize( b_s );

	a = a_s;
	b = b_s;
	c = c_s;
}

void normalize( Vec3D &a )
{
	float length_vec = 0;
	for ( int i = 0; i < M3D - 1; i++ )
		length_vec += a[i] * a[i];
	length_vec = sqrt( length_vec );

	for ( int i = 0; i < M3D - 1; i++ )
		a[i] /= length_vec;

	a[M3D - 1] = 1;
}

void mult( Mat3D a, float koef, Mat3D &c )
{
	unit(c);

	for ( int i = 0; i < M3D; i++ )
		for ( int j = 0; j < M3D; j++ )
			c[i][j] = a[i][j] * koef;
}

void mult( Vec3D a, float koef, Vec3D &c )
{
	for ( int i = 0; i < M3D - 1; i++ )
		c[i] = a[i] * koef;

	c[M3D - 1] = 1;
}

void multVec( Vec3D a, Vec3D b, Vec3D &c )
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
	c[3] = 1;
}

void sum( Mat3D a, Mat3D b, Mat3D &c )
{
	unit(c);

	for ( int i = 0; i < M3D; i++ )
		for ( int j = 0; j < M3D; j++ )
			c[i][j] = a[i][j] + b[i][j];
}

void sum( Vec3D a, Vec3D b, Vec3D &c )
{
	for ( int i = 0; i < M3D - 1; i++ )
		c[i] = a[i] + b[i];

	c[M3D - 1] = 1;
}
#pragma once
#include "stdafx.h"
#include "Transform.h"
#include <math.h>

Mat T;

void times( Mat a, Mat b, Mat c )
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

void timesMatVec( Mat a, Vec b, Vec c )
{
	for ( int i = 0; i < M; i++ )
	{
		float skalaar = 0;
		for ( int j = 0; j < M; j++ )
			skalaar += a[i][j] * b[j];
		c[i] = skalaar;
	}
}

void set( Mat a, Mat b )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			b[i][j] = a[i][j];
}

void point2vec( TPoint a, Vec b )
{
	b[0] = a.x;
	b[1] = a.y;
	b[2] = 1;
}

void vec2point( Vec a, TPoint &b )
{
	b.x = ( (float)a[0] ) / a[2];
	b.y = ( (float)a[1] ) / a[2];
}

void makeHomogenVec( float x, float y, Vec c )
{
	c[0] = x;
	c[1] = y;
	c[2] = 1;
}

void unit( Mat a )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			if ( i == j )
				a[i][j] = 1;
			else
				a[i][j] = 0;
}

void move( float t_x, float t_y, Mat c )
{
	unit(c);
	c[0][M - 1] = t_x;
	c[1][M - 1] = t_y;
}

void rotate( float centre_x, float centre_y, float phi, Mat c )
{
	unit(c);

	c[0][0] = cos(phi);
	c[0][1] = -sin(phi);
	c[0][2] = centre_x * ( 1.0 - cos(phi) ) + centre_y * sin(phi);

	c[1][0] = sin(phi);
	c[1][1] = cos(phi);
	c[1][2] = centre_y * ( 1.0 - cos(phi) ) - centre_x * sin(phi);
}

void scale( float s_x, float s_y, Mat c )
{
	unit(c);
	c[0][0] = s_x;
	c[1][1] = s_y;
}

void reflectVertical( Mat a )
{
	unit(a);
	a[0][0] = -1;
}

void reflectHorizontal( Mat a )
{
	unit(a);
	a[1][1] = -1;
}

void frame( float v_x, float v_y, float v_cx, float v_cy, 	float w_x, float w_y, float w_cx, float w_cy, 	Mat c ){	Mat R, T1;	move( -v_cx, -v_cy, c );	scale( w_x / v_x, w_y / v_y, R );	times( R, c, T1 );	set( T1, c );	reflectHorizontal( R );
	times( R, c, T1 );
	set( T1, c );		move( w_cx, w_cy, R );	times( R, c, T1 );	set( T1, c );}
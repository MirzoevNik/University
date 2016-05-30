#pragma once
#include "stdafx.h"
#include "clip.h"
#include <algorithm>

using namespace std;

int calcAreaCode( TPoint a, TPoint p_min, TPoint p_max )
{
	int c = 0;

	if ( a.x < p_min.x )
		c++;
	if ( a.x > p_max.x )
		c += 2;
	if ( a.y < p_min.y )
		c += 4;
	if ( a.y > p_max.y )
		c += 8;

	return c;
}

bool clip( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	if ( a.x > b.x )
		std::swap( a, b );
	if ( p_min.x > p_max.x )
		std::swap( p_min.x, p_max.x );
	if ( p_min.y > p_max.y )
		std::swap( p_min.y, p_max.y );

	// коды областей
	int c1 = calcAreaCode( a, p_min, p_max );
	int c2 = calcAreaCode( b, p_min, p_max );

	if ( ( c1 & c2 ) != 0 )
	{
		return false;
	}

	int c = c1 * 16 + c2;

	// основные случаи
	if ( c == 0x00 )
		return true;

	if ( c == 0x18)
	{
		clip1Left( a, b,  p_min,  p_max );

		if ( a.y > p_max.y )
			return false;
		else
		{
			clip2Top( a, b,  p_min,  p_max );
			return true;
		}
	}

	if ( c == 0x1A)
	{
		clip1Left( a, b,  p_min,  p_max );
		if ( a.y >  p_max.y )
			return false;
		else
			clip2Top( a, b,  p_min,  p_max );

		if ( b.x >  p_max.x )
			clip2Right( a, b,  p_min,  p_max );
		return true;
	}

	if ( c == 0x10)
	{
		clip1Left( a, b,  p_min,  p_max );
		return true;
	}

	if ( c == 0x12)
	{
		clip1Left( a, b,  p_min,  p_max );
		clip2Right( a, b,  p_min,  p_max );
		return true;
	}

	if ( c == 0x50)
	{
		clip1Left( a, b,  p_min,  p_max );
		if ( a.y <  p_min.y )
			clip1Bottom( a, b,  p_min,  p_max );
		return true;
	}

	if ( c == 0x5A)
	{
		clip1Left( a, b,  p_min,  p_max );
		if ( a.y >  p_max.y )
			return false;
		else
		{
			if ( a.y <  p_min.y )
			{
				clip1Bottom( a, b,  p_min,  p_max );
				if ( a.x >  p_max.x )
					return false;
			}

			clip2Top( a, b,  p_min,  p_max );

			if ( b.x >  p_max.x )
				clip2Right( a, b,  p_min,  p_max );
			return true;
		}
	}

	// симметричные случаи

	bool result = true;

	if ( c == 0x02 )
	{
		reflectVertical( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}

	if ( c == 0x04 )
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}

	if ( c == 0x08 )
	{
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
	}
	
	if ( c == 0x06)
	{
		reflectVertical( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}
	
	if ( c == 0x0A)
	{
		reflectVertical( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}
	
	if ( c == 0x14)
	{
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
	}
	
	if ( c == 0x16)
	{
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
	}
	
	if ( c == 0x40)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}
	
	if ( c == 0x42)
	{
		reflectVertical( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}
	
	if ( c == 0x48)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}
	
	if ( c == 0x52)
	{
		reflectVertical( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}
	
	if ( c == 0x58)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}

	if ( c == 0x80)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}
	
	if ( c == 0x82)
	{
		reflectVertical( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}
	
	if ( c == 0x84)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}
	
	if ( c == 0x86)
	{
		rotate( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}

	if ( c == 0x90)
	{
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
	}

	if ( c == 0x92)
	{
		reflectVertical( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}

	if ( c == 0x94)
	{
		rotate( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectHorizontal( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
		rotate( a, b, p_min, p_max );
	}

	if ( c == 0x96 )
	{
		reflectVertical( a, b, p_min, p_max );
		result = clip( a, b, p_min, p_max );
		reflectVertical( a, b, p_min, p_max );
	}

	return result;
}

void clip1Left( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 a.y =  b.y - (  b.x - p_min.x ) * (  b.y -  a.y ) / (  b.x -  a.x );
	 a.x = p_min.x;
}
void clip1Top( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 a.x =  b.x - (  b.y - p_max.y ) * (  b.x -  a.x ) / (  b.y -  a.y );
	 a.y = p_max.y;
}

void clip1Bottom( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 a.x =  b.x - (  b.y - p_min.y ) * (  b.x -  a.x ) / (  b.y -  a.y );
	 a.y = p_min.y;
}

void clip2Right( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 b.y =  a.y + ( p_max.x -  a.x ) * (  b.y -  a.y ) / (  b.x -  a.x );
	 b.x = p_max.x;
}

void clip2Top( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 b.x =  a.x + ( p_max.y -  a.y ) * (  b.x -  a.x ) / (  b.y -  a.y );
	 b.y = p_max.y;
}

void clip2Bottom( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max )
{
	 b.x =  a.x + ( p_min.y -  a.y ) * (  b.x -  a.x ) / (  b.y -  a.y );
	 b.y = p_min.y;
}

void rotate( TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max )
{
	swap( a.x, a.y );
	swap( b.x, b.y );
	a.x = -a.x;
	b.x = -b.x;

	swap( p_min.x, p_min.y );
	swap( p_max.x, p_max.y );
	p_min.x = -p_min.x;
	p_max.x = -p_max.x;
}

void reflectVertical( TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max )
{
	a.x = -a.x;
	b.x = -b.x;
	p_min.x = -p_min.x;
	p_max.x = -p_max.x;
}

void reflectHorizontal( TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max )
{
	a.y = -a.y;
	b.y = -b.y;
	p_min.y = -p_min.y;
	p_max.y = -p_max.y;
}
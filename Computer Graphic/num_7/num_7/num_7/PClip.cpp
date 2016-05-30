#pragma once
#include "stdafx.h"
#include "PClip.h"

using namespace std;

Polygon^ pClip ( Polygon^ p, TPoint p_min, TPoint p_max )
{
	Polygon ^p1 = gcnew Polygon();
	int n = p->Count;
	int k = 0;
	int n1 = 0;

	TPoint start = p[ n - 1 ];
	int c_start = extCode( start, p_min, p_max );

	while ( k < n )
	{
		TPoint end = p[ k ];
		int c_end = extCode( end, p_min, p_max );

		int c1 = c_start;
		int c2 = c_end;
		TPoint tp1 = start;
		TPoint tp2 = end;

		bool clip = false;
		bool flip = false;
		bool segm;

		while ( true )
		{
			if ( ( ( c1 | c2 ) & 15 ) == 0 )
			{
				if ( flip )
				{
					swap( tp1, tp2 );
				}

				segm = true;
				break;
			}
			else
			{
				if ( ( c1 & c2 & 15 ) != 0 )
				{
					segm = false;
					break;
				}
				else
				{
					if ( ( c1 & 15 ) == 0 )
					{
						swap( tp1, tp2 );
						swap( c1, c2 );
						flip = !flip;
					}

					if ( ( ( c1 & 15) != 0 ) && ( !flip ) )
					{
						clip = true;
					}

					TPoint save_tp1 = tp1;
					
					if ( ( c1 & 1 ) != 0 )
					{
						tp1.y = tp2.y - ( tp2.x - p_min.x ) * ( ( tp2.y - tp1.y ) / ( tp2.x - tp1.x ) );
						tp1.x = p_min.x;
					}
					
					if ( ( c1 & 2 ) != 0 )
					{
						tp1.y = tp2.y - ( tp2.x - p_max.x ) * ( ( tp2.y - tp1.y ) / ( tp2.x - tp1.x ) );
						tp1.x = p_max.x;
					}
					
					if ( ( c1 & 4 ) != 0 )
					{
						tp1.x = tp2.x - ( tp2.y - p_min.y ) * ( ( tp2.x - tp1.x ) / ( tp2.y - tp1.y ) );
						tp1.y = p_min.y;
					}
					
					if ( ( c1 & 8 ) != 0 )
					{
						tp1.x = tp2.x - ( tp2.y - p_max.y ) * ( ( tp2.x - tp1.x ) / ( tp2.y - tp1.y ) );
						tp1.y = p_max.y;
					}

					c1 = extCode( tp1, p_min, p_max );
				}
			}
		}

		c2 = c_end;
		if ( segm )
		{
			if ( clip )
			{
				p1->Add( tp1 );
				n1++;
			}
			
			p1->Add( tp2 );
			n1++;
		}
		else
		{
			if ( ( c_end & 16 ) != 0 )
			{
				if ( ( c_start & c_end & 15 ) == 0 )
				{
					if ( ( c_start & 16 ) == 0 )
					{
						c1 = c_end + tcc( c_start );
					}
					else
					{
						tp1 = start;
						tp2 = end;
						int c11 = c_start;
						int c12 = c_end;

						while ( true )
						{
							TPoint mid;
							mid.x = ( tp1.x + tp2.x ) / 2;
							mid.y = ( tp1.y + tp2.y ) / 2;

							c1 = extCode( mid, p_min, p_max );

							if ( ( c1 & 16 ) != 0 )
							{
								if ( c1 == c12 )
								{
									tp2 = mid;
									c12 = c1;
								}
								else if ( c1 == c11 )
								{
									tp1 = mid;
									c11 = c1;
								}
								else
								{
									if ( ( c1 & c12 ) != 0 )
										c1 = c11 + tcc( c1 );
									else
										c1 = c12 + tcc( c1 );

									break;
								}
							}
						}
					}

					p1->Add( angle( c1, p_min, p_max ) );
					n1++;
				}
			}
			else
			{
				if ( ( c_start & c_end & 15 ) == 0 )
				{
					if ( ( c_start & 16 ) != 0 )
						c2 = c_start + tcc( c_end );
					else
						c2 = c_start + c_end + 16;		
				}
			}
		}

		if ( ( c2 & 16 ) != 0 )
		{
			p1->Add( angle( c2, p_min, p_max ) );
			n1++;
		}

		k++;
		c_start = c_end;
		start = end;

	}

	return p1;
}

int extCode( TPoint p, TPoint p_min, TPoint p_max )
{
	int c = 0;

	if ( p.x < p_min.x )
	{
		c++;
		if ( p.y < p_min.y )
		{
			c += 20;
		}
		else if ( p.y > p_max.y )
		{
			c += 24;
		}
	}
	else if ( p.x > p_max.x )
	{
		c += 2;
		if ( p.y < p_min.y )
		{
			c += 20;
		}
		else if ( p.y > p_max.y )
		{
			c += 24;
		}
	}
	else if ( p.y < p_min.y )
	{
		c += 4;
	}
	else if ( p.y > p_max.y )
	{
		c += 8;
	}

	return c;
}

TPoint angle( int c, TPoint p_min, TPoint p_max )
{
	TPoint p;

	if ( c & 1 )
		p.x = p_min.x;
	if ( c & 2 )
		p.x = p_max.x;
	if ( c & 4 )
		p.y = p_min.y;
	if ( c & 8 )
		p.y = p_max.y;

	return p;
}

int tcc( int c )
{
	int corr;

	if ( c & 1 )
		corr = -1;
	if ( c & 2 )
		corr = 1;
	if ( c & 4 )
		corr = -4;
	if ( c & 8 )
		corr = 4;

	return corr;
}
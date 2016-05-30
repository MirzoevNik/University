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

void pFill( Polygon^ p, System::Drawing::Bitmap^ image, System::Drawing::Color c, TPoint p_min, TPoint p_max, System::Drawing::Color color_frame )
{
	stack< TPoint* > s;

	TPoint *pi = &innerPoint( p );
	
	if ( pi->y > p_min.y + 1 && pi->y <= p_max.y + 1 )
	{
		s.push( pi );

		while ( !s.empty() )
		{
			TPoint pj = *( s.top() );
			s.pop();

			System::Drawing::Color c_xy = image->GetPixel( pj.x, pj.y );

			if ( c_xy.ToArgb() != c.ToArgb() )
			{
				int x_max = pj.x;
				int x_min = pj.x;

				while ( x_min > p_min.x && pj.y >= p_min.y && pj.y <= p_max.y )
				{
					System::Drawing::Color c_min = image->GetPixel( x_min - 1, pj.y );
					if ( c_min.ToArgb() != c.ToArgb() )
						x_min--;
					else
						break;
				}

				while ( x_max < p_max.x && pj.y >= p_min.y && pj.y <= p_max.y )
				{
					System::Drawing::Color c_max = image->GetPixel( x_max + 1, pj.y );
					if ( c_max.ToArgb() != c.ToArgb() )
						x_max++;
					else
						break;
				}
			
				for ( int i = x_min; i <= x_max; i++ )
				{
					image->SetPixel( i, pj.y, c );
				}

				bool flag1 = false;
				bool flag2 = false;
				for ( int px = x_min; px <= x_max; px++ )
				{
					if ( !flag1 && pj.y < p_max.y && pj.x >= p_min.x && pj.x <= p_max.x )
					{
						System::Drawing::Color c_up = image->GetPixel( px, pj.y + 1 );
						if ( c_up.ToArgb() != c.ToArgb() )
						{
							TPoint *p_up = new TPoint();
							p_up->x = px;
							p_up->y = pj.y + 1;

							s.push( p_up );
							if ( flag2 )
								break;
							flag1 = true;
						}
					}

					if ( !flag2 && pj.y > p_min.y && pj.x >= p_min.x && pj.x <= p_max.x )
					{
						System::Drawing::Color c_dn = image->GetPixel( px, pj.y - 1 );
						if ( c_dn.ToArgb() != c.ToArgb() )
						{
							TPoint *p_dn = new TPoint();
							p_dn->x = px;
							p_dn->y = pj.y - 1;

							s.push( p_dn );
							if ( flag1 )
								break;
							flag2 = true;
						}
					}
				}
			}
		}
	}
}

TPoint innerPoint( Polygon ^p )
{
	TPoint inner_point = p[0];

	TPoint p_s = p[0], p_ss;
	bool p_ss_find = false;

	for ( int i = 0; i < p->Count; i++ )
	{
		if ( !p_ss_find && p[i].y != p_s.y )
		{
			p_ss = p[i];
			p_ss_find = true;
		}
		else if ( p[i].y != p_s.y && p[i].y < p_s.y )
		{
			p_ss = p_s;
			p_s = p[i];
		}
		else if ( p[i].y != p_s.y && p[i].y < p_ss.y )
		{
			p_ss = p[i];
		}

		if ( p_ss_find && p_ss.y < p_s.y )
		{
			swap( p_s, p_ss );
		}
	}

	TPoint sec_p_s1, sec_p_s2;
	sec_p_s1.x = -1;
	sec_p_s2.x = -1;

	TPoint a = p[ p->Count - 1 ];
	for ( int i = 0; i < p->Count; i++ )
	{
		TPoint b = p[i];

		TPoint start = a, end = b;
		if ( start.y > end.y )
			swap( start, end );

		if ( start.y == p_s.y && start.y != end.y )
		{
			if ( sec_p_s1.x == -1 )
			{
				sec_p_s1 = end;
			}
			else if ( sec_p_s2.x == -1 )
			{
				sec_p_s2 = end;
				if ( sec_p_s1.x > sec_p_s2.x )
				{
					swap( sec_p_s1, sec_p_s2 );
				}
			}
			else
			{
				if ( end.x < sec_p_s1.x  )
				{
					sec_p_s2 = sec_p_s1;
					sec_p_s1 = end;
				}
				else if ( end.x < sec_p_s2.x )
				{
					sec_p_s2 = end;
				}
			}
		}

		a = b;
	}

	if ( sec_p_s1.x == sec_p_s2.x && sec_p_s1.y == sec_p_s2.y )
	{
		TPoint start1, start2;
		start1.x = -1;
		start2.x = -1;

		TPoint a = p[ p->Count - 1 ];
		for ( int i = 0; i < p->Count; i++ )
		{
			TPoint b = p[i];

			TPoint start = a, end = b;
			if ( start.y > end.y )
				swap( start, end );

			if ( start1.x == -1 )
			{
				if ( end.x == sec_p_s1.x && end.y == sec_p_s1.y )
					start1 = start;
			}
			else if ( start2.x == -1 )
			{
				if ( end.x == sec_p_s1.x && end.y == sec_p_s1.y )
					start2 = start;
			}

			a = b;
		}

		inner_point.x = ( ( start1.x + sec_p_s1.x ) / 2.0 
						+ ( start2.x + sec_p_s2.x ) / 2.0 ) / 2.0;
		inner_point.y = ( ( start1.y + sec_p_s1.y ) / 2.0 
						+ ( start2.y + sec_p_s2.y ) / 2.0 ) / 2.0;
	}
	else
	{
		inner_point.x = ( ( p_s.x + sec_p_s1.x ) / 2.0 
						+ ( p_s.x + sec_p_s2.x ) / 2.0 ) / 2.0;
		inner_point.y = ( ( p_s.y + sec_p_s1.y ) / 2.0 
						+ ( p_s.y + sec_p_s2.y ) / 2.0 ) / 2.0;
	}
	
	return inner_point;
}
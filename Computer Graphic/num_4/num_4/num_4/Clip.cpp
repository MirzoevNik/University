#pragma once
#include "stdafx.h"
#include "Clip.h"
#include <algorithm>

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

	TPoint a_start = a;

	// коды областей
	int c1 = calcAreaCode( a, p_min, p_max );
	int c2 = calcAreaCode( b, p_min, p_max );

	if ( (c1 & c2) != 0 )
	{
		return false;
	}
	else
	{
		float d_x = b.x - a.x;
		float d_y = b.y - a.y;

		switch ( c1 )
		{
		case 0:
			{
				if ( c2 == 0 )
					return true;

				if ( d_y >= 0 )
				{
					float d_x_r = p_max.x - a.x;
					float d_y_t = p_max.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_t )
					{
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					}
					else
					{
						clip2Top( a_start, b, d_x, d_y, d_y_t );
					}

					return true;
				}
				else
				{
					float d_x_r = p_max.x - a.x;
					float d_y_b = p_min.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_b )
					{
						clip2Bottom( a_start, b, d_x, d_y, d_y_b );
					}
					else
					{
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					}

					return true;
				}

				break;
			}

		case 1:
			{
				float d_x_l = p_min.x - a.x;
				float d_y_t = p_max.y - a.y;

				if ( c2 == 0 )
				{
					clip1Left( a_start, a, d_x, d_y, d_x_l );
					return true;
				}

				if ( d_y >= 0 )
				{
					if ( d_y * d_x_l > d_x * d_y_t )
						return false;
					
					float d_x_r = p_max.x - a.x;
					d_y_t = p_max.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_t )
					{
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					}
					else
					{
						clip2Top( a_start, b, d_x, d_y, d_y_t );
					}

					clip1Left( a_start, a, d_x, d_y, d_x_l );

					return true;
				}
				else
				{
					float d_y_b = p_min.y - a.y;
					d_x_l = p_min.x - a.x;

					if ( d_y * d_x_l < d_x * d_y_b )
						return false;

					float d_x_r = p_max.x - a.x;
					d_y_b = p_min.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_b )
					{
						clip2Bottom( a_start, b, d_x, d_y, d_y_b );
					}
					else
					{
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					}

					clip1Left( a_start, a, d_x, d_y, d_x_l );

					return true;
				}

				break;
			}

		case 4:
			{
				float d_x_r = p_max.x - a.x;
				float d_y_b = p_min.y - a.y;

				if ( c2 == 0 )
				{
					clip1Bottom( a_start, a, d_x, d_y, d_y_b );

					return true;
				}

				if ( d_y > 0 )
				{
					if ( d_y * d_x_r < d_x * d_y_b )
						return false;

					float d_y_t = p_max.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_t )
					{
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					}
					else
					{
						clip2Top( a_start, b, d_x, d_y, d_y_t );
					}

					clip1Bottom( a_start, a, d_x, d_y, d_y_b );

					return true;
				}
				else
					return false;

				break;
			}

		case 5:
			{
				if ( d_y > 0 )
				{
					float d_x_l = p_min.x - a.x;
					float d_y_t = p_max.y - a.y;

					if ( d_y * d_x_l > d_x * d_y_t )
						return false;

					float d_x_r = p_max.x - a.x;
					float d_y_b = p_min.y - a.y;

					if ( d_y * d_x_r < d_x * d_y_b )
						return false;

					if ( d_y_b * d_x_r < d_x_l * d_y_t )
					{
						if ( d_y * d_x_l < d_x * d_y_b )
						{
							clip1Bottom( a_start, a, d_x, d_y, d_y_b );

							if ( b.x > p_max.x )
								clip2Right( a_start, b, d_x, d_y, d_x_r );

							return true;
						}

						clip1Left( a_start, a, d_x, d_y, d_x_l );

						if ( c2 == 0 )
							return true;

						if ( d_y * d_x_r < d_x * d_y_t && c2 != 0 )
						{
							clip2Right( a_start, b, d_x, d_y, d_x_r );

							return true;
						}

						clip2Top( a_start, b, d_x, d_y, d_y_t );

						return true;
					}
					else
					{
						if ( d_y * d_x_r < d_x * d_y_t )
						{
							clip1Bottom( a_start, a, d_x, d_y, d_y_b );

							if ( b.x > p_max.x )
							{
								clip2Right( a_start, b, d_x, d_y, d_x_r );

								return true;
							}
						}

						if ( d_y * d_x_l < d_x * d_y_b )
						{
							clip1Bottom( a_start, a, d_x, d_y, d_y_b );

							if ( c2 != 0 )
								clip2Top( a_start, b, d_x, d_y, d_y_t );

							return true;
						}

						clip1Left( a_start, a, d_x, d_y, d_x_l );

						if ( c2 == 0 )
							return true;

						clip2Top( a_start, b, d_x, d_y, d_y_t );

						return true;
					}
				}
				else
				{
					return false;
				}

				break;
			}

		case 8:
			{
				float d_x_r = p_max.x - a.x;
				float d_y_t = p_max.y - a.y;

				if ( c2 == 0 )
				{
					clip1Top( a_start, a, d_x, d_y, d_y_t );

					return true;
				}

				if ( d_y < 0 )
				{
					if ( d_y * d_x_r > d_x * d_y_t )
						return false;

					float d_y_b = p_min.y - a.y;

					if ( d_y * d_x_r > d_x * d_y_b )
						clip2Right( a_start, b, d_x, d_y, d_x_r );
					else
						clip2Bottom( a_start, b, d_x, d_y, d_y_b );

					clip1Top( a_start, a, d_x, d_y, d_y_t );

					return true;
				}
				else
					return false;

				break;
			}

		case 9:
			{
				if ( d_y < 0 )
				{
					float d_x_r = p_max.x - a.x;
					float d_y_t = p_max.y - a.y;

					if ( d_y * d_x_r > d_x * d_y_t )
						return false;

					float d_x_l = p_min.x - a.x;
					float d_y_b = p_min.y - a.y;

					if ( d_y * d_x_l < d_x * d_y_b )
						return false;

					if ( d_y_t * d_x_r > d_x_l * d_y_b )
					{
						if ( d_y * d_x_l > d_x * d_y_t )
						{
							clip1Top( a_start, a, d_x, d_y, d_y_t );

							if ( b.x > p_max.x )
								clip2Right( a_start, b, d_x, d_y, d_x_r );

							return true;
						}

						clip1Left( a_start, a, d_x, d_y, d_x_l );

						if ( c2 == 0 )
							return true;

						if ( d_y * d_x_r > d_x * d_y_b )
						{
							clip2Right( a_start, b, d_x, d_y, d_x_r );

							return true;
						}

						clip2Bottom( a_start, b, d_x, d_y, d_y_b );

						return true;
					}
					else
					{
						if ( d_y * d_x_r > d_x * d_y_b )
						{
							clip1Top( a_start, a, d_x, d_y, d_y_t );

							if ( b.x > p_max.x )
								clip2Right( a_start, b, d_x, d_y, d_x_r );

							return true;
						}

						if ( d_y * d_x_l > d_x * d_y_t )
						{
							clip1Top( a_start, a, d_x, d_y, d_y_t );

							if ( c2 != 0 )
								clip2Bottom( a_start, b, d_x, d_y, d_y_b );

							return true;
						}

						clip1Left( a_start, a, d_x, d_y, d_x_l );

						if ( c2 != 0 )
						{
							clip2Bottom( a_start, b, d_x, d_y, d_y_b );
						}

						return true;
					}
				}
				else
					return false;

				break;

				}
		}
	}

	return false;
}

void clip1Left( TPoint a_start, TPoint &a, float d_x, float d_y, float d_x_l )
{
	a.y = a_start.y + d_x_l * ( d_y / d_x );
	a.x = a_start.x + d_x_l;
}

void clip1Top( TPoint a_start, TPoint &a, float d_x, float d_y, float d_y_t )
{
	a.x = a_start.x + d_y_t * ( d_x / d_y );
	a.y = a_start.y + d_y_t;
}

void clip1Bottom( TPoint a_start, TPoint &a, float d_x, float d_y, float d_y_b )
{
	a.x = a_start.x + d_y_b * ( d_x / d_y );
	a.y = a_start.y + d_y_b;
}

void clip2Right( TPoint a_start, TPoint &b, float d_x, float d_y, float d_x_r )
{
	b.y = a_start.y + d_x_r * ( d_y / d_x );
	b.x = a_start.x + d_x_r;
}

void clip2Top( TPoint a_start, TPoint &b, float d_x, float d_y, float d_y_t )
{
	b.x = a_start.x + d_y_t * ( d_x / d_y );
	b.y = a_start.y + d_y_t;
}

void clip2Bottom( TPoint a_start, TPoint &b, float d_x, float d_y, float d_y_b )
{
	b.x = a_start.x + d_y_b * ( d_x / d_y );
	b.y = a_start.y + d_y_b;
}
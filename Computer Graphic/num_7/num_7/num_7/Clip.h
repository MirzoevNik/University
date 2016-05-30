#pragma once
#include "Transform.h"

bool clip( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max ); // процедура отсечения отрезков (Николь-Ли-Николь)
int calcAreaCode( TPoint a, TPoint p_min, TPoint p_max ); // вычисление кода области

void clip1Left( TPoint a_start, TPoint &a, float d_x, float d_y, float d_x_l );
void clip1Top( TPoint a_start, TPoint &a, float d_x, float d_y, float d_y_t );
void clip1Bottom( TPoint a_start, TPoint &a, float d_x, float d_y, float d_y_b );
void clip2Right( TPoint a_start, TPoint &b, float d_x, float d_y, float d_x_r );
void clip2Top( TPoint a_start, TPoint &b, float d_x, float d_y, float d_y_t );
void clip2Bottom( TPoint a_start, TPoint &b, float d_x, float d_y, float d_y_b );
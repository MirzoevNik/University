#pragma once
#include "Transform.h"

bool clip( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max ); // процедура отсечения отрезков (FC-алгоритм)
int calcAreaCode( TPoint a, TPoint p_min, TPoint p_max ); // вычисление кода области

void clip1Left( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );
void clip1Top( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );
void clip1Bottom( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );
void clip2Right( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );
void clip2Top( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );
void clip2Bottom( TPoint &a, TPoint &b, TPoint p_min, TPoint p_max );

void rotate(  TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max );
void reflectVertical( TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max );
void reflectHorizontal( TPoint &a, TPoint &b, TPoint &p_min, TPoint &p_max );
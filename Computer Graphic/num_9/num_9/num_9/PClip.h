#pragma once
#include "Transform.h"

Polygon^ pClip ( Polygon^ p, TPoint p_min, TPoint p_max ); // ��������� ��������� �������������� ���'��
int extCode( TPoint p, TPoint p_min, TPoint p_max );
TPoint angle( int c, TPoint p_min, TPoint p_max );
int tcc( int c );
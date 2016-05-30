#include "Vertex.h"

Vertex::Vertex(int v)
{
	value = v;
	color = 0;
}

void Vertex::setColor(short c)
{
	color = c;
}

int Vertex::getValue()
{
	return value;
}
	
short Vertex::getColor()
{
	return color;
}

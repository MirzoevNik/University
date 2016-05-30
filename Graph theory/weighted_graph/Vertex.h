#pragma once
class Vertex
{
private:
	int value; // значение вершины
	short color; // цвет вершины

public:
	Vertex(int v);

	void setColor(short c);

	int getValue();
	short getColor();
};


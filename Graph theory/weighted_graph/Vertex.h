#pragma once
class Vertex
{
private:
	int value; // �������� �������
	short color; // ���� �������

public:
	Vertex(int v);

	void setColor(short c);

	int getValue();
	short getColor();
};


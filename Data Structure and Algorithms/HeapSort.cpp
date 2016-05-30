#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename S>
class HeapSort
{
private:
	vector< S > mas; // ������ ������

	void heapSort(); // Heap sort
	void siftDown(int index, int size); // ����������� ������ - ���������� ��������� ������ (�������� � 2 �������)

public:
	HeapSort(vector< S > massiv);
	~HeapSort(void);

	vector< S > getMas(); // ��������� ���������������� �������
};

template <typename S>
HeapSort< S >::HeapSort(vector< S > massiv)
{
	mas = massiv;

	heapSort(); // ���������� ������� � ������� Heap sort
}

template <typename S>
HeapSort< S >::~HeapSort(void)
{
}

template <typename S>
vector <S> HeapSort< S >::getMas()
{
	return mas;
}

template <typename S>
void HeapSort< S >::heapSort()
{
	for ( int i = mas.size() / 2 - 1; i >= 0; i-- )
		siftDown( i, mas.size() ); // ������ �������� ������ �� ��������� � �����

	int last_not_sort = mas.size(); // ���������� ����������������� ������� �������
	while ( last_not_sort > 1 )
	{
		last_not_sort--;
		swap( mas[0], mas[last_not_sort] ); // ������ �������� � ����� ������������������ ������
		siftDown( 0, last_not_sort ); // ������ �������� ������ �� ��������� � �����
	}
}

template <typename S>
void HeapSort< S >::siftDown(int index, int size)
{
	int max = index;
	while (true)
	{
		int child = 2 * index + 1; // ������� � ������� ������
		if ( ( child < size ) && ( mas[ child ] > mas[ max ] ) )
			max = child; // ��������, ��� ������ ������ �������� �������
		child++; // ������� �� ������� ������

		if ( ( child < size ) && ( mas[ child ] > mas[ max ] ) )
			max = child; // ��������, ��� ������ ������ �������� �������

		if ( max == index ) // ���� ��� ������ - ����
		{
			break; // ������ �������� ������ �����
		}

		swap( mas[ index ], mas[ max ] ); // �������� �������� ���������
		index = max;
	}
}

// �������� ����� � �������
void generateData(string name_file, int count_elems)
{
	srand( time( NULL ) );

	ofstream out(name_file);
	for (int i = 0; i < count_elems; i++)
	{
		out << rand() % 10000;
		if ( i + 1 < count_elems )
			out << endl;
	}
	out.close();
}

// ���������� ������ �� �����
template <typename S>
void readData(vector< S > &mas, string name_file)
{
	ifstream in(name_file);
	while( in.peek() != EOF )
	{
		S elem;
		in >> elem;
		mas.push_back(elem);
	}
	in.close();
}

// ����� ������ � ����
template <typename S>
void printData(vector< S > mas, string name_file)
{
	ofstream out(name_file);
	for (int i = 0; i < mas.size(); i++)
		out << mas[i] << endl;
	out.close();
}

int main()
{
	int count_elements = 1000; // ���������� ��������� � �������
	generateData( "input_heap_sort.txt", count_elements );

	vector < int > mas;
	readData < int > (mas, "input_heap_sort.txt");
	
	HeapSort < int > *heap_sort = new HeapSort < int > (mas);
	mas = heap_sort->getMas();

	printData < int > (mas, "output_heap_sort.txt");

	return 0;
}
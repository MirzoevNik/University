#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class CountingSort
{
private:
	vector< int > mas; // ������ ������
	
	void countingSort(int max_elem); // Counting sort

public:
	CountingSort(vector< int > massiv, int max_elem);
	~CountingSort(void);

	vector< int > getMas(); // ��������� ���������������� �������
};

CountingSort::CountingSort(vector< int > massiv, int max_elem)
{
	mas = massiv;

	countingSort( max_elem ); // ���������� ������� � ������� Counting sort
}

CountingSort::~CountingSort(void)
{
}

vector< int > CountingSort::getMas()
{
	return mas;
}

void CountingSort::countingSort(int max_elem) // max_elem - ������������ ������� � �������
{
	vector< int > mas_counts( max_elem, 0 ); // ������, ���������� ���������� ������� �������� �� 0 �� max_elem, �������������� 0

	for ( int i = 0; i < mas.size(); i++ )
		mas_counts[ mas[i] ]++; // ��������� ������ mas_counts ����������, ���������������� ���������� � �������� ������� ����� � mas[i]-��� ���������

	int pos = 0; // ���������, � ������� �������� ��������� �������� ������ ��� ���������������� �������
	for ( int numb = 0; numb < max_elem; numb++ ) // numb - �����, ������������ � �������� �������
	{
		for ( int i = 0; i < mas_counts[numb]; i++ ) // ��������� mas_counts[numb] ����� � mas
		{
			mas[pos] = numb;
			pos++;
		}
	}
}

// �������� ����� � �������
void generateData(string name_file, int count_elems, int max_elem)
{
	srand( time( NULL ) );

	ofstream out(name_file);
	for (int i = 0; i < count_elems; i++)
	{
		out << rand() % max_elem;
		if ( i + 1 < count_elems )
			out << endl;
	}
	out.close();
}

// ���������� ������ �� �����
void readData(vector< int > &mas, string name_file)
{
	ifstream in(name_file);
	while( in.peek() != EOF )
	{
		int elem;
		in >> elem;
		mas.push_back(elem);
	}
	in.close();
}

// ����� ������ � ����
void printData(vector< int > mas, string name_file)
{
	ofstream out(name_file);
	for (int i = 0; i < mas.size(); i++)
		out << mas[i] << endl;
	out.close();
}

int main()
{
	setlocale(LC_ALL, "rus");

	int max_elem; // ������������ ������� �������
	while (true)
	{
		cout << "������� ������������ ������� �������: ";
		cin >> max_elem;
		if ( max_elem < 0)
		{
			cout << "������! ������� ������������� ��������!" << endl;
		}
		else
		{
			break;
		}
	}

	int count_elements = 1000; // ���������� ��������� � �������
	generateData( "input_counting_sort.txt", count_elements, max_elem );

	vector< int > mas; // ������ � �������
	readData( mas, "input_counting_sort.txt" );
	
	CountingSort *counting_sort = new CountingSort( mas, max_elem );
	mas = counting_sort->getMas();

	printData( mas, "output_counting_sort.txt" );

	return 0;
}
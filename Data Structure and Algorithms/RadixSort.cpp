#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class RadixSort
{
private:
	vector< int > mas; // ������ ������
	int static const k = 10; // ��������� ������� ����������
	int static const m = 3; // ������������ ���-�� ��������
	
	void radixSort(int left, int right, int dis); // Radix sort
	int digit(int num, int dis); // ������������ ����� � ������� dis ����� num

public:
	RadixSort(vector< int > massiv);
	~RadixSort(void);

	vector< int > getMas(); // ��������� ���������������� �������
};

RadixSort::RadixSort(vector< int > massiv)
{
	mas = massiv;

	radixSort( 0, mas.size(), 0 ); // ���������� ������� � ������� Radix sort
}

RadixSort::~RadixSort(void)
{
}

vector< int > RadixSort::getMas()
{
	return mas;
}

void RadixSort::radixSort( int left, int right, int dis )
{
	for ( int i = 0; i < m; i++ ) // �������� �� ���� �������� �����(�������������) �� 0 �� m
	{
         vector < int> mas_count( k, 0 ); // ������, ���������� ���������� ������ ����� (�� 0 �� k) �� i-�� �������, �������������� 0

         for (int j = 0; j < mas.size(); j++ )
		 {
             int dig = digit( mas[j], i ); // ������� ��� ���� ����� ������� �����, ������� �� i-�� �������
             mas_count[ dig ]++; // ������������ ���������� ������ �����, ������� �� i-�� ������� ����� ���� ����� 
		 }

         int count = 0;
         for ( int j = 0; j < k; j++)
		 {
             int tmp = mas_count[j];
             mas_count[j] = count; // ���������� �������, � ������� ������ ������������� �������� � ������ j � i-�� �������
             count += tmp;
		 }

		 vector < int > mas_need( mas.size() ); // ��������������� ������, � ������� ��������� ������������� ���������� ���������� �� 0 �� i-��� �������
         for ( int j = 0; j < mas.size(); j++)
		 {
             int dig = digit( mas[j], i );                             
             mas_need[ mas_count[ dig ] ] = mas[j]; // ������ ������� ������� � ������ �������          
             mas_count[ dig ]++;
		 }

         mas = mas_need; // ��������� �������� ������� mas_need � mas
	}
}

int RadixSort::digit(int num, int dis)
{
	int digit = 0;
	int count = 0;

	while ( num > 0 && count <= dis )
	{
		if ( count == dis )
			digit = num % 10; // ��������� �����, ������� � dis-�� ������� � ����� num
		num /= 10; // ��������� ������ �����
		count++;
	}

	return digit;
}

// �������� ����� � �������
void generateData(string name_file, int count_elems)
{
	srand( time( NULL ) );

	ofstream out(name_file);
	for (int i = 0; i < count_elems; i++)
	{
		out << rand() % 1000;
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
	int count_elements = 1000; // ���������� ��������� � �������
	generateData( "input_radix_sort.txt", count_elements );

	vector< int > mas;
	readData (mas, "input_radix_sort.txt");
	
	RadixSort *radix_sort = new RadixSort(mas);
	mas = radix_sort->getMas();

	printData (mas, "output_radix_sort.txt");

	return 0;
}
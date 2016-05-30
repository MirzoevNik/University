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
	vector< int > mas; // массив данных
	
	void countingSort(int max_elem); // Counting sort

public:
	CountingSort(vector< int > massiv, int max_elem);
	~CountingSort(void);

	vector< int > getMas(); // получение отсортированного массива
};

CountingSort::CountingSort(vector< int > massiv, int max_elem)
{
	mas = massiv;

	countingSort( max_elem ); // сортировка массива с помощью Counting sort
}

CountingSort::~CountingSort(void)
{
}

vector< int > CountingSort::getMas()
{
	return mas;
}

void CountingSort::countingSort(int max_elem) // max_elem - максимальный элемент в массиве
{
	vector< int > mas_counts( max_elem, 0 ); // массив, содержащий количество каждого элемента от 0 до max_elem, инициализируем 0

	for ( int i = 0; i < mas.size(); i++ )
		mas_counts[ mas[i] ]++; // заполняем массив mas_counts значениями, соответствующими количеству в исходном массиве чисел с mas[i]-тым значением

	int pos = 0; // указатель, с помощью которого заполняем исходный массив уже отсортированными данными
	for ( int numb = 0; numb < max_elem; numb++ ) // numb - число, содержащееся в исходном массиве
	{
		for ( int i = 0; i < mas_counts[numb]; i++ ) // вставляем mas_counts[numb] чисел в mas
		{
			mas[pos] = numb;
			pos++;
		}
	}
}

// создание файла с данными
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

// считывание данных из файла
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

// вывод данных в файл
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

	int max_elem; // максимальный элемент массива
	while (true)
	{
		cout << "Введите максимальный элемент массива: ";
		cin >> max_elem;
		if ( max_elem < 0)
		{
			cout << "Ошибка! Введите положительное значение!" << endl;
		}
		else
		{
			break;
		}
	}

	int count_elements = 1000; // количество элементов в массиве
	generateData( "input_counting_sort.txt", count_elements, max_elem );

	vector< int > mas; // массив с данными
	readData( mas, "input_counting_sort.txt" );
	
	CountingSort *counting_sort = new CountingSort( mas, max_elem );
	mas = counting_sort->getMas();

	printData( mas, "output_counting_sort.txt" );

	return 0;
}
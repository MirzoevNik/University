#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename S>
class MergeSort
{
private:
	vector< S > mas; // массив данных

	void doMerge(int left, int middle, int right); // сделать слияние
	void mergeSort(int left, int right); // Merge sort

public:
	MergeSort(vector< S > massiv);
	~MergeSort(void);

	vector< S > getMas(); // получение отсортированного массива
};

template <typename S>
MergeSort< S >::MergeSort(vector< S > massiv)
{
	mas = massiv;

	mergeSort( 0, mas.size() ); // сортировка массива с помощью Merge sort
}

template <typename S>
MergeSort< S >::~MergeSort(void)
{
}

template <typename S>
vector< S > MergeSort< S >::getMas()
{
	return mas;
}

template <typename S>
void MergeSort< S >::mergeSort(int left, int right)
{
	if (left + 1 >= right)
		return;
	int mid = (right + left) / 2; // средний элемент
	mergeSort( left, mid ); // сортировка левой части
	mergeSort( mid, right ); // сортировка правой части
	doMerge( left, mid, right ); // слияние трёх частей и среднего элемента
}

template <typename S>
void MergeSort< S >::doMerge(int left, int middle, int right)
{
	vector < S > res( right - left); // массив, в который будем "сливать" элементы

	int i = 0, j = 0;
	while ( left + i < middle && middle + j < right )
		if ( mas[left + i] < mas[middle + j] ) // выбираем наименьший элемент из двух частей
		{
			res[i + j] = mas[left + i]; // вставляем элемент из левой части
			i++;
		}
		else
		{
			res[i + j] = mas[middle + j]; // вставляем элемент из правой части
			j++;
		}

	while ( left + i < middle )
	{
		res[i + j] = mas[left + i]; // "досливаем" элементы из левой части, если такие остались
		i++;
	}

	while ( middle + j < right )
	{
		res[i + j] = mas[middle + j]; // "досливаем" элементы из правой части, если такие остались
		j++;
	}

	for (int k = 0; k < i + j; k++)
		mas[left + k] = res[k]; // помещаем в mas на нужные позиции отсортированный массив res
}

// создание файла с данными
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

// считывание данных из файла
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

// вывод данных в файл
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
	int count_elements = 1000; // количество элементов в массиве
	generateData( "input_merge_sort.txt", count_elements );

	vector < int > mas;
	readData < int > (mas, "input_merge_sort.txt");
	
	MergeSort < int > *merge_sort = new MergeSort < int > (mas);
	mas = merge_sort->getMas();

	printData < int > (mas, "output_merge_sort.txt");

	return 0;
}

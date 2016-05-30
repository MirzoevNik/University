#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename S>
class QuickSort
{
private:
	vector< S > mas; // массив данных

	int partition(int left, int right); // разделение
	void quickSort(int left, int right); // Quick sort

public:
	QuickSort(vector< S > massiv);
	~QuickSort(void);

	vector< S > getMas(); // получение отсортированного массива
};

template <typename S>
QuickSort< S >::QuickSort(vector< S > massiv)
{
	mas = massiv;

	quickSort( 0, mas.size() ); // сортировка массива с помощью Quick sort
}

template <typename S>
QuickSort< S >::~QuickSort(void)
{
}

template <typename S>
vector <S> QuickSort< S >::getMas()
{
	return mas;
}

template <typename S>
void QuickSort< S >::quickSort(int left, int right)
{
	if ( left < right - 1 )
	{
		int q = partition( left, right - 1 ); // разбиение на две части массива и выбор среднего элемента
		quickSort( left, q ); // сортировка левой части
		quickSort( q, right ); // сортировка правой части
	}
}

template <typename S>
int QuickSort< S >::partition(int left, int right)
{
	S x = mas[ ( left + right ) / 2 ]; // средний элемент
	
	int i = left;
	int j = right;
	while ( i <= j )
	{
		while (mas[i] < x)
			i++;
		while (mas[j] > x)
			j--;
		if (i <= j)
		{
			swap(mas[i], mas[j]); // в левую часть помещаем число, котрое меньше x, а в правую - больше x
			i++;
			j--;
		}
	}

	return i;
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
	generateData( "input_quick_sort.txt", count_elements );

	vector < int > mas;
	readData < int > (mas, "input_quick_sort.txt");
	
	QuickSort < int > *quick_sort = new QuickSort < int > (mas);
	mas = quick_sort->getMas();

	printData < int > (mas, "output_quick_sort.txt");

	return 0;
}

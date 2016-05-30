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
	vector< S > mas; // массив данных

	void heapSort(); // Heap sort
	void siftDown(int index, int size); // просеивание данных - построение двоичного дерева (родитель и 2 ребенка)

public:
	HeapSort(vector< S > massiv);
	~HeapSort(void);

	vector< S > getMas(); // получение отсортированного массива
};

template <typename S>
HeapSort< S >::HeapSort(vector< S > massiv)
{
	mas = massiv;

	heapSort(); // сортировка массива с помощью Heap sort
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
		siftDown( i, mas.size() ); // строим двоичное дерево из родителей и детей

	int last_not_sort = mas.size(); // послелдний неотсортированный элемент массива
	while ( last_not_sort > 1 )
	{
		last_not_sort--;
		swap( mas[0], mas[last_not_sort] ); // ставим родителя в конец неотсортированного списка
		siftDown( 0, last_not_sort ); // строим двоичное дерево из родителей и детей
	}
}

template <typename S>
void HeapSort< S >::siftDown(int index, int size)
{
	int max = index;
	while (true)
	{
		int child = 2 * index + 1; // переход к первому ребёнку
		if ( ( child < size ) && ( mas[ child ] > mas[ max ] ) )
			max = child; // проверка, что первый ребёнок является ребёнком
		child++; // переход ко второму ребёнку

		if ( ( child < size ) && ( mas[ child ] > mas[ max ] ) )
			max = child; // проверка, что второй ребёнок является ребёнком

		if ( max == index ) // если оба ребёнка - дети
		{
			break; // значит родитель выбран верно
		}

		swap( mas[ index ], mas[ max ] ); // выбираем родителя правильно
		index = max;
	}
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
	generateData( "input_heap_sort.txt", count_elements );

	vector < int > mas;
	readData < int > (mas, "input_heap_sort.txt");
	
	HeapSort < int > *heap_sort = new HeapSort < int > (mas);
	mas = heap_sort->getMas();

	printData < int > (mas, "output_heap_sort.txt");

	return 0;
}
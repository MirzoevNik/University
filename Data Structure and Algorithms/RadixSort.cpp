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
	vector< int > mas; // массив данных
	int static const k = 10; // основание системы счистления
	int static const m = 3; // максимальное кол-во разрядов
	
	void radixSort(int left, int right, int dis); // Radix sort
	int digit(int num, int dis); // опеределение цифры в разряде dis числа num

public:
	RadixSort(vector< int > massiv);
	~RadixSort(void);

	vector< int > getMas(); // получение отсортированного массива
};

RadixSort::RadixSort(vector< int > massiv)
{
	mas = massiv;

	radixSort( 0, mas.size(), 0 ); // сортировка массива с помощью Radix sort
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
	for ( int i = 0; i < m; i++ ) // проходим по всем разрядам числа(максимального) от 0 до m
	{
         vector < int> mas_count( k, 0 ); // массив, содержащий количество каждой цифры (от 0 до k) на i-ом разряде, инициализируем 0

         for (int j = 0; j < mas.size(); j++ )
		 {
             int dig = digit( mas[j], i ); // находим для всех чисел массива цифру, стоящую на i-ом разряде
             mas_count[ dig ]++; // подсчитываем количество каждой цифры, стоящей на i-ом разряде среди всех чисел 
		 }

         int count = 0;
         for ( int j = 0; j < k; j++)
		 {
             int tmp = mas_count[j];
             mas_count[j] = count; // выставляем позицию, с которой должны располагаться элементы с цифрой j в i-ом разряде
             count += tmp;
		 }

		 vector < int > mas_need( mas.size() ); // вспомогательный массив, в который запишутся промежуточные результаты сортировки от 0 до i-ого разряда
         for ( int j = 0; j < mas.size(); j++)
		 {
             int dig = digit( mas[j], i );                             
             mas_need[ mas_count[ dig ] ] = mas[j]; // ставим элемент массива в нужную позицию          
             mas_count[ dig ]++;
		 }

         mas = mas_need; // переносим элементы массива mas_need в mas
	}
}

int RadixSort::digit(int num, int dis)
{
	int digit = 0;
	int count = 0;

	while ( num > 0 && count <= dis )
	{
		if ( count == dis )
			digit = num % 10; // получение цифры, стоящей в dis-ом разряде в числе num
		num /= 10; // отсечение правой цифры
		count++;
	}

	return digit;
}

// создание файла с данными
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
	int count_elements = 1000; // количество элементов в массиве
	generateData( "input_radix_sort.txt", count_elements );

	vector< int > mas;
	readData (mas, "input_radix_sort.txt");
	
	RadixSort *radix_sort = new RadixSort(mas);
	mas = radix_sort->getMas();

	printData (mas, "output_radix_sort.txt");

	return 0;
}
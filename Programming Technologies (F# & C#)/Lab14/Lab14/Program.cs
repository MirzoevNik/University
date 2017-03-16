using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab14
{
    class Program
    {
        static int countSort = 0;
        static int countSearchDichotomy = 0;
        static int countEasySearch = 0;

        static void Main(string[] args)
        {
            Random random = new Random();
            int[] mas = new int[100];
            Console.WriteLine("Исходный массив:");
            for (int i = 0; i < 100; i++)
            {
                mas[i] = random.Next(-100, 100);
                Console.WriteLine("{0}", mas[i]);
            }

            Console.Write("\nВведите элемент для поиска: ");
            int k = int.Parse(Console.ReadLine());

            IndexOf(ref mas, k);
            SelectionSort(ref mas);
            IndexOf(ref mas, k, 0, mas.Length);

            Console.WriteLine("\nКоличество итераций в алгоритме простого поиска: {0}", countEasySearch);
            Console.WriteLine("Количество итераций в сортировке выбором: {0}", countSort);
            Console.WriteLine("Количество итераций в алгоритме поиска дихотомией: {0}", countSearchDichotomy);

            Console.ReadLine();
        }

        // Простой поиск элемента в массиве
        static int IndexOf(ref int[] Array, int Value)
        {
            // Перебираем все элементы массива
            for (int i = 0; i < Array.Length; i++)
            {
                countEasySearch++;
                // Если нашли нужное значение, то возвращаем его индекс
                if (Array[i] == Value)
                    return i;
            }
            // Перебор закончился безрезультатно - возвращаем -1
            return -1;
        }


        // Сортировка выбором
        static void SelectionSort(ref int[] Array)
        {
            // Перебираем все элементы массива (кроме последнего)
            // i - позиция первого неотсортированного элемента
            for (int i = 0; i < Array.Length - 1; i++)
            {
                // Позиция минимального элемента справа от i
                int min = i;
                // Перебираем все элементы справа от i
                for (int j = i + 1; j < Array.Length; j++)
                {
                    countSort++;
                    // Меньше ли очередной элемент минимального?
                    if (Array[j] < Array[min])
                        min = j; // Да - теперь это новый минимальный элемент
                                 // Минимальный элемент не на первом месте? Меняем местами!
                }
                if (min != i)
                {
                    int t = Array[i];
                    Array[i] = Array[min];
                    Array[min] = t;
                }
            }
        }

        // Дихотомический поиск элемента в массиве
        static int IndexOf(ref int[] Array, int Value, int Left, int Right)
        {
            countSearchDichotomy++;
            // Находим середину диапазона
            int x = (Left + Right) / 2;
            // Если нашли значение - возвращаем его индекс
            if (Array[x] == Value)
                return x;
            // Если середина совпадает с левой или правой границами - значение не найдено
            if ((x == Left) || (x == Right))
                return -1;
            // Продолжаем поиск слева или справа от середины
            if (Array[x] < Value)
                return IndexOf(ref Array, Value, x, Right);
            else
                return IndexOf(ref Array, Value, Left, x);
        }
    }
}
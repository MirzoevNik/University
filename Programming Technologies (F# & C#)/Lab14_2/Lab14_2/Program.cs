using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab14_2
{
    class Program
    {
        static void Main()
        {
            Quadrangle first = new Quadrangle();
            first.a = 2;
            first.b = 3;
            first.c = 4;
            first.d = 5;

            Console.WriteLine("Периметр четырехугольника = {0}", first.GetPerimeter());

            if (!first.isRectangle())
            {
                Console.WriteLine("Данный четырехугольник не прямоугольник.");
            }

            Quadrangle second = new Quadrangle();

            Console.WriteLine("Периметр четырехугольника = {0}", second.GetPerimeter());

            if (second.isRectangle())
            {
                Console.WriteLine("Данный четырехугольник прямоугольник.");
            }
            else
            {
                Console.WriteLine("Данный четырехугольник не прямоугольник.");
            }

            Console.WriteLine("Введите а");
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите b");
            int b = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите b");
            int c = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите b");
            int d = int.Parse(Console.ReadLine());

            Quadrangle my_quad = new Quadrangle(a, b, c, d);

            Console.WriteLine("Периметр четырехугольника = {0}", my_quad.GetPerimeter());

            if (my_quad.isRectangle())
            {
                Console.WriteLine("Данный четырехугольник прямоугольник.");
            }
            else
            {
                Console.WriteLine("Данный четырехугольник не прямоугольник.");
            }

            Console.WriteLine("Значение поля а: {0}", my_quad.A);

            Console.WriteLine("Значение поля c: {0}", my_quad.C);

            Console.Read();
        }
    }
}

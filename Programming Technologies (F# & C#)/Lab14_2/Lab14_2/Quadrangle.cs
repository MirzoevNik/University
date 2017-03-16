using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab14_2
{
    class Quadrangle
    {
        public int a;
        public int b;
        public int c;
        public int d;

        public Quadrangle()
        {
            a = 1;
            b = 1;
            c = 1;
            d = 1;
        }

        public Quadrangle(int a, int b, int c, int d)
        {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }

        ~Quadrangle()
        {
            System.Diagnostics.Trace.WriteLine("Quadrangles destructor is called.");
        }

        //только для чтения
        public int A
        {
            get
            {
                return a;
            }
        }

        //только для записи
        public int B
        {
            set
            {
                b = value;
            }
        }

        //для записи и чтения
        public int C
        {
            set
            {
                c = value;
            }
            get
            {
                return c;
            }
        }

        //для записи и чтения
        public int D
        {
            set
            {
                d = value;
            }
            get
            {
                return d;
            }
        }

        public int GetPerimeter()
        {
            return (a + b + c + d);
        }

        public bool isRectangle()
        {
            return (a == c && b == d);
        }
    }
}

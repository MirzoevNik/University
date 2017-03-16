using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab13
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            /* 11)	Написать метод, который вычисляет значения x=sin2(a) и y=cos2(a). Напечатать таблицу значений от –π до π с шагом π/4. */
            for (double a = -Math.PI; a <= Math.PI; a += Math.PI / 4.0)
            {
                double x = 0.0;
                double y = 0.0;
                calc(ref x, ref y, a);
                textBox1.Text += "a = " + Convert.ToString(a) +
                                 "; x = " + Convert.ToString(x) +
                                 "; y = " + Convert.ToString(y) + Environment.NewLine;
            }
        }

        private void calc(ref double x, ref double y, double a)
        {
            x = Math.Pow(Math.Sin(a), 2);
            y = Math.Pow(Math.Cos(a), 2);
        }
    }
}

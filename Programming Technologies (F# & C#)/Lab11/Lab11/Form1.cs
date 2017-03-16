using System;
using System.Windows.Forms;

namespace Lab11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void calculateBtn_Click(object sender, EventArgs e)
        {
            try
            {
                double dx = Convert.ToDouble(textBoxDx.Text);
                printFunction(dx);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Input error!\n" + ex.StackTrace);
            }
        }

        private void calculateStepLessBtn_Click(object sender, EventArgs e)
        {
            try
            {
                double dx = Convert.ToDouble(textBoxDx.Text);
                printFunction(dx / 2.0);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Input error!\n" + ex.StackTrace);
            }
        }

        private void printFunction(double dx)
        {
            textBoxResult.Clear();

            double x0 = Convert.ToDouble(textBoxX0.Text);
            double xk = Convert.ToDouble(textBoxXk.Text);
            double a = Convert.ToDouble(textBoxA.Text);
            double b = Convert.ToDouble(textBoxB.Text);
            textBoxResult.Text = "Работу выполнил ст. Мирзоев Н.Р." + Environment.NewLine;

            double x = x0;
            while (Math.Abs(x) <= Math.Abs(xk + dx / 2.0))
            {
                double y = x + Math.Sqrt(Math.Abs(Math.Pow(x, 3) + a
                                                    - b * Math.Exp(x)));
                textBoxResult.Text += "x = " + Convert.ToString(x) +
                                 "; y = " + Convert.ToString(y) + Environment.NewLine;
                x += dx;
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Lab10
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textBoxX.Clear();
            textBoxY.Clear();
            textBoxZ.Clear();
            textBoxResult.Clear();
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                double x = Convert.ToDouble(textBoxX.Text);
                double y = Convert.ToDouble(textBoxY.Text);
                double z = Convert.ToDouble(textBoxZ.Text);

                textBoxResult.Text = "Результаты работы программы ст. Мирзоева Н.Р. " + Environment.NewLine;
                textBoxResult.Text += "При X = " + textBoxX.Text + Environment.NewLine;
                textBoxResult.Text += "При Y = " + textBoxY.Text + Environment.NewLine;
                textBoxResult.Text += "При Z = " + textBoxZ.Text + Environment.NewLine;

                double f = 0.0;
                if (radioButtonSh.Checked)
                {
                    f = Math.Sinh(x);
                }
                if (radioButtonX2.Checked)
                {
                    f = Math.Pow(x, 2);
                }
                else if (radioButtonEx.Checked)
                {
                    f = Math.Exp(x);
                }

                double m = Math.Max(Math.Max(f, y), z)
                            / Math.Min(f, y)
                            + 5;
                textBoxResult.Text += "M = " + Convert.ToString(m) + Environment.NewLine;

            }
            catch (Exception ex)
            {
                MessageBox.Show("Input error!\n{0}", ex.StackTrace);
            }
        }
    }
}

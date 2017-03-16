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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, EventArgs e)
        {
            try
            {
                double x = double.Parse(textBoxX.Text);
                double y = double.Parse(textBoxY.Text);
                double z = double.Parse(textBoxZ.Text);
                double b = Math.Pow(y, Math.Pow(Math.Abs(x), 1 / 3.0))
                    + Math.Pow(Math.Cos(y), 3)
                        * Math.Abs(x - y)
                        * (1 + Math.Pow(Math.Sin(z), 2) / Math.Sqrt(x + y))
                        / (Math.Exp(Math.Abs(x - y)) + x / 2.0);
                textBoxB.Text = b.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Input error!\n{0}", ex.StackTrace);
            }
        }
    }
}
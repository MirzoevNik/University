using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab11
{
    public partial class Form3 : Form
    {
        static int COUNT = 25; 
        int[] r = new int[COUNT];

        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            textBox1.Text = "";
            for (int i = 0; i < COUNT; i++)
            {
                r[i] = rand.Next(-50, 50);
                textBox1.Text += "R[" + Convert.ToString(i) + "] = "
                    + Convert.ToString(r[i]) + Environment.NewLine;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
            for (int i = 0; i < COUNT; i++)
            {
                if (r[i] < 0)
                {
                    r[i] *= r[i];
                }
                else if (r[i] > 0)
                {
                    r[i] += 7;
                }
                textBox2.Text += "R[" + Convert.ToString(i) + "] = "
                                  + Convert.ToString(r[i]) + Environment.NewLine;
            }
        }
    }
}

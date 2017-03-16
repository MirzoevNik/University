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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            listBox2.Items.Add("Line is first is it.");
            listBox2.Items.Add("Line is second is it.");
            listBox2.Items.Add("Line is third is it.");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string line = listBox1.SelectedItem.ToString();
                makeTask(line);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Input error!\n" + ex.StackTrace);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string line = listBox2.SelectedItem.ToString();
                makeTask(line);
            }
            catch(Exception ex)
            {
                MessageBox.Show("Input error!\n" + ex.StackTrace);
            }
        }

        private void makeTask(string line)
        {
            int i = int.Parse(textBox1.Text);
            int j = int.Parse(textBox2.Text);
            string result = swapSymbols(line, i, j);
            label3.Text = result;
        }

        private string swapSymbols(string line, int i, int j)
        {
            int count = 0;
            int realI = 0;
            int realJ = 0;
            for (int k = 0; k < line.Length; k++)
            {
                char symbol = line[k];
                if ((symbol >= 'a' && symbol <= 'z') 
                    || (symbol >= 'A' && symbol <= 'Z'))
                {
                    if (count.Equals(i))
                    {
                        realI = k;
                    }
                    if (count.Equals(j))
                    {
                        realJ = k;
                    }
                    count++;
                }
            }
            char tmp = line[realI];
            line = line.Remove(realI, 1).Insert(realI, line[realJ].ToString());
            line = line.Remove(realJ, 1).Insert(realJ, tmp.ToString());
            return line;
        }
    }
}
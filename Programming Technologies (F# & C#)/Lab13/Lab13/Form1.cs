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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.Clear(Color.Black);

            Random rand = new Random();
            int cx = rand.Next(5, ClientSize.Width - 5);
            int cy = rand.Next(5, ClientSize.Height - 5);

            SolidBrush goldBrush = new SolidBrush(Color.Gold);

            // Create points that define polygon.
            Point[] points = new Point[10];
            points[0] = new Point(cx + 2, cy - 2);
            points[1] = new Point(cx, cy - 5);
            points[2] = new Point(cx - 2, cy - 2);
            points[3] = new Point(cx - 5, cy);
            points[4] = new Point(cx - 2, cy);
            points[5] = new Point(cx - 5, cy + 5);
            points[6] = new Point(cx, cy + 2);
            points[7] = new Point(cx + 5, cy + 5);
            points[8] = new Point(cx + 2, cy);
            points[9] = new Point(cx + 5, cy);

            // Draw polygon to screen.
            g.FillPolygon(goldBrush, points);
        }
    }
}
 
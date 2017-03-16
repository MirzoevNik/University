using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab12
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            // Create solid brush.
            SolidBrush indigoBrush = new SolidBrush(Color.Indigo);

            // Create points that define polygon.
            Point point1 = new Point(50, 50);
            Point point2 = new Point(100, 50);
            Point point3 = new Point(125, 100);
            Point point4 = new Point(75, 150);
            Point point5 = new Point(25, 100);
            Point[] curvePoints = { point1, point2, point3, point4, point5 };

            // Draw polygon to screen.
            g.FillPolygon(indigoBrush, curvePoints);
            g.DrawEllipse(new Pen(Brushes.Brown, 3), 150, 150, 50, 100);

            // создание объекта
            Pen skyBluePen = new Pen(Brushes.DeepSkyBlue);
            // задает линию из штирихов
            skyBluePen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
            // усанавливает ширину линии
            skyBluePen.Width = 1.0F;

            // общий стиль оконччания для двух последовательных линий
            skyBluePen.LineJoin = System.Drawing.Drawing2D.LineJoin.Bevel;

            // рисование объекта
            e.Graphics.DrawRectangle(skyBluePen,
                new Rectangle(240, 40, 150, 200));

            // Освобождает все ресурсы исп. данным объектом
            skyBluePen.Dispose();

            Pen myPen = new Pen(Brushes.Aqua);
            // задает линию из штирихов
            myPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDotDot;
            // усанавливает ширину линии
            myPen.Width = 3.0F;

            // общий стиль оконччания для двух последовательных линий
            myPen.LineJoin = System.Drawing.Drawing2D.LineJoin.Round;

            g.DrawRectangle(myPen, 450, 200, 100, 100);
        }
    }
}

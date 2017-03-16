using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab12
{
    public partial class Form2 : Form
    {
        private double XMin = -Math.PI;
        private double XMax = Math.PI;
        private double Step = (Math.PI * 2) / 10;

        // Массив значений X
        private double[] x;

        // Два массива Y
        private double[] y;

        Chart chart;

        public Form2()
        {
            InitializeComponent();
        }

        private void CalcFunction()
        {
            // Количество точек графика
            int count = (int)Math.Ceiling((XMax - XMin) / Step)
                        + 1;
            // Создаём массивы нужных размеров
            x = new double[count];
            y = new double[count];
            double a = 0.1;
            double b = 3.5;
            // Расчитываем точки для графика функции
            for (int i = 0; i < count; i++)
            {
                // Вычисляем значение X
                x[i] = XMin + Step * i;
                // Вычисляем значение функции в точке X
                y[i] = x[i] + Math.Sqrt(Math.Abs(Math.Pow(x[i], 3) + a
                                        - b * Math.Exp(x[i])));
            }
        }

        private void CreateChart()
        {
            // Создаём новый элемент управления Chart
            chart = new Chart();
            // Помещаем его на форму
            chart.Parent = this;
            // Задаём размеры элемента
            chart.SetBounds(10, 10, ClientSize.Width - 20,
                            ClientSize.Height - 20);

            // Создаём новую область для построения графика
            ChartArea area = new ChartArea();
            // Даём ей имя (чтобы потом добавлять графики)
            area.Name = "myGraph";
            // Задаём левую и правую границы оси X
            area.AxisX.Minimum = XMin;
            area.AxisX.Maximum = XMax;
            // Определяем шаг сетки
            area.AxisX.MajorGrid.Interval = Step;
            // Добавляем область в диаграмму
            chart.ChartAreas.Add(area);

            // Создаём объект для первого графика
            Series series1 = new Series();
            // Ссылаемся на область для построения графика
            series1.ChartArea = "myGraph";
            // Задаём тип графика - сплайны
            series1.ChartType = SeriesChartType.Spline;
            // Указываем ширину линии графика
            series1.BorderWidth = 3;
            // Название графика для отображения в легенде
            series1.LegendText = "y";
            // Добавляем в список графиков диаграммы
            chart.Series.Add(series1);

            // Создаём легенду, которая будет показывать названия
            Legend legend = new Legend();
            chart.Legends.Add(legend);
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // Создаём элемент управления
            CreateChart();

            // Расчитываем значения точек графиков функций
            CalcFunction();

            // Добавляем вычисленные значения в графики
            chart.Series[0].Points.DataBindXY(x, y);
        }
    }
}
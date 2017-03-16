open System
open System.Collections.Generic
open System.Windows.Forms
open System.ComponentModel
open System.Drawing

let graphicForm = new Form(Text = "Различные примеры (F#) :: Рисование объектов на форме", AutoScaleDimensions = new System.Drawing.SizeF(60.0F, 13.0F), ClientSize = new System.Drawing.Size(700, 700), StartPosition = FormStartPosition.CenterScreen)

graphicForm.Paint.Add(fun draw ->
let array1 = [|new Point(50, 300);new Point(50, 200);new Point(150, 50);new Point(250, 50);new Point(250, 600);new Point(150, 600);new Point(150, 150)|]
let array2 = [|new Point(350, 300);new Point(350, 200);new Point(450, 50);new Point(550, 50);new Point(550, 600);new Point(450, 600);new Point(450, 150)|]
let pen = new Pen(Color.Blue, Width = 10.0f)
let brush = new SolidBrush(Color.LightGreen)
draw.Graphics.DrawPolygon(pen, array1)
draw.Graphics.FillPolygon(brush, array1)
draw.Graphics.DrawPolygon(pen, array2)
draw.Graphics.FillPolygon(brush, array2))

let exitButton = new Button(Text = "Выход", Location = new System.Drawing.Point(600, 650), Size = new Size(75, 23))
exitButton.Click.Add(fun quit -> graphicForm.Close())
graphicForm.Controls.Add(exitButton)   

Application.Run(graphicForm)
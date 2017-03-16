module task2

open System
open System.Windows.Forms
open System.Drawing
Application.EnableVisualStyles()
let form = new Form(Width=302, Height=350,Text = "Работа со списками")
let button1 = new Button(Left=21, Top=32, Text="ПУСК", Width=96, Height=23)
let textBox1 = new TextBox(Left=156, Top=32, Width=114, Height=20)

form.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
form.ClientSize = new System.Drawing.Size(302, 314);
form.Controls.Add(textBox1);
form.Controls.Add(button1);

button1.Click.AddHandler(fun _ _ -> 
    let list1 = [1; 2; -3; 5; -6]
    let list2 = List.filter (fun x -> x >= 0) list1                  
    textBox1.Text<-  (list2 |> Seq.map string |> String.concat ", "))

form.Text = "Работа со списками";
form.ResumeLayout(false);
form.PerformLayout();

Application.Run(form)

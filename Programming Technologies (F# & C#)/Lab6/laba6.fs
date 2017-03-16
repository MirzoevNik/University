module laba6

open System
open System.Windows.Forms
open System.Drawing

let imageForm = new Form(Text = "Приложение с выбором рисунка", 
                         AutoScaleDimensions = new System.Drawing.SizeF(60.0F, 13.0F), 
                         ClientSize = new System.Drawing.Size(1000, 600), 
                         StartPosition = FormStartPosition.CenterScreen)

// Создаём элементы управления
let exitButton = new Button(Text = "Выход", 
                            Location=new System.Drawing.Point(900, 550))
let loadButton = new Button(Text = "Загрузить", 
                            Location=new System.Drawing.Point(800, 550))
let pictureBox = new PictureBox(SizeMode = PictureBoxSizeMode.StretchImage, 
                                Location = new System.Drawing.Point(20, 20), 
                                BorderStyle = BorderStyle.FixedSingle, 
                                Size = new System.Drawing.Size(400, 480))
let pictureBox2 = new PictureBox(SizeMode = PictureBoxSizeMode.StretchImage, 
                                Location = new System.Drawing.Point(440, 20), 
                                BorderStyle = BorderStyle.FixedSingle, 
                                Size = new System.Drawing.Size(540, 480))

let openFileDialog = new OpenFileDialog()

imageForm.Controls.Add(pictureBox)
imageForm.Controls.Add(pictureBox2)
imageForm.Controls.Add(loadButton)
imageForm.Controls.Add(exitButton)

// События нажатия кнопок
loadButton.Click.Add(fun load ->
        openFileDialog.Filter <- "Изображения JPEG (*.jpg,*.jpeg)|*.jpg;*.jpeg|Изображения GIF (*.gif)|*.gif" 
        openFileDialog.Title <- "Приложение с выбором рисунка :: Выбор файла изображения" 
        if (openFileDialog.ShowDialog() = DialogResult.OK) then
            // Создаём растровый рисунок и снимаем поворот и отражение (если есть)
            let bitmap = new System.Drawing.Bitmap(openFileDialog.FileName)
            bitmap.RotateFlip(RotateFlipType.RotateNoneFlipNone)
            // Перемещаем старое изображение во второй блок
            pictureBox2.Image <- pictureBox.Image
            // Помещаем выбранное изображение в первый блок
            pictureBox.Image <- bitmap)


exitButton.Click.Add(fun quit2 -> imageForm.Close())

[<STAThreadAttribute>]
Application.Run(imageForm)
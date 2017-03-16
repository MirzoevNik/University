module laba7

open System
open System.IO
open System.Windows
open System.Windows.Controls
open System.Windows.Markup

let pathXML = "laba7.xml";
let mwXaml = System.IO.File.ReadAllText(pathXML);
let getWindow(mwXaml) =
    let xamlObj=XamlReader.Parse(mwXaml)
    xamlObj :?> Window

let window = getWindow(mwXaml)
let textBox1 = window.FindName("textBox1") :?> TextBox
let checkBox21 = window.FindName("checkBox21") :?> CheckBox
let checkBox22 = window.FindName("checkBox22") :?> CheckBox
let checkBox23 = window.FindName("checkBox23") :?> CheckBox
let checkBox24 = window.FindName("checkBox24") :?> CheckBox
let checkBox25 = window.FindName("checkBox25") :?> CheckBox
let radioButton31 = window.FindName("radioButton31") :?> RadioButton
let checkBox41 = window.FindName("checkBox41") :?> CheckBox
let checkBox42 = window.FindName("checkBox42") :?> CheckBox
let checkBox43 = window.FindName("checkBox43") :?> CheckBox
let checkBox44 = window.FindName("checkBox44") :?> CheckBox
let checkBox45 = window.FindName("checkBox45") :?> CheckBox
let textBox5 = window.FindName("textBox5") :?> TextBox
let buttonAnswer = window.FindName("buttonAnswer") :?> Button

buttonAnswer.Click.AddHandler(fun _ _ -> 
    let resultOk = sprintf "Тест пройден упешно!"
    let resultWrong = sprintf "Тест не пройден!"
    let answer1 = "функция, вызывающая саму себя"
    let answer5 = "XAML"

    if (textBox1.Text.Trim().ToLower().Equals(answer1)
        && checkBox21.IsChecked.Value
        && checkBox22.IsChecked.Value
        && not checkBox23.IsChecked.Value
        && checkBox24.IsChecked.Value
        && not checkBox25.IsChecked.Value
        && radioButton31.IsChecked.Value
        && checkBox41.IsChecked.Value
        && not checkBox42.IsChecked.Value
        && checkBox43.IsChecked.Value
        && not checkBox44.IsChecked.Value
        && checkBox45.IsChecked.Value
        && textBox5.Text.Trim().ToUpper().Equals(answer5)) then
        MessageBox.Show(resultOk) |> ignore
    else
        MessageBox.Show(resultWrong) |> ignore)

[<STAThread>] ignore <| (new Application()).Run window
open System
open System.Windows
open System.Windows.Controls
open System.Windows.Markup

let mwXaml = " 
<Window xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'
        xmlns:x='http://schemas.microsoft.com/winfx/2006/xaml'
        xmlns:d='http://schemas.microsoft.com/expression/blend/2008'
        xmlns:mc='http://schemas.openxmlformats.org/markup-compatibility/2006'
        xmlns:local='clr-namespace:LayoutApp'
        mc:Ignorable='d'
        Title='Мирзоев Никита Романович, 11 вариант' Height='250' Width='1300'>
 <Grid ShowGridLines='True'>
        <Grid.RowDefinitions>
            <RowDefinition></RowDefinition>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='*'></ColumnDefinition>
            <ColumnDefinition Width='0.5*'></ColumnDefinition>
        </Grid.ColumnDefinitions>
        <Button Grid.Row='0' Grid.Column='0' Background='Red' >Строка 1. Столбец 1.</Button>
        <Button Grid.Row='0' Grid.Column='1' Background='Green'>Строка 1. Столбец 2.</Button>
        <Button Grid.Row='0' Grid.Column='2' Background='Blue'>Строка 1. Столбец 3.</Button>
        <Button Grid.Row='0' Grid.Column='3' Background='Yellow'>Строка 1. Столбец 4.</Button>
        <Button Grid.Row='0' Grid.Column='4' Background='Black' Foreground='White'>Строка 1. Столбец 5.</Button>
        <Button Grid.Row='0' Grid.Column='5' Background='Khaki'>Строка 1. Столбец 6.</Button>
        <Button Grid.Row='0' Grid.Column='6' Background='Purple'>Строка 1. Столбец 7.</Button>
        <Button Grid.Row='0' Grid.Column='7' Background='LightGreen'>Строка 1. Столбец 8.</Button>
        <Button Grid.Row='0' Grid.Column='8' Background='Orange'>Строка 1. Столбец 9.</Button>
        <Button Grid.Row='0' Grid.Column='9' Background='Brown'>Строка 1.Столбец 10.</Button>
    </Grid>

</Window>
" 
let getWindow(mwXaml) =
    let xamlObj=XamlReader.Parse(mwXaml)
    xamlObj :?> Window

let win = getWindow(mwXaml)

[<STAThread>] ignore <| (new Application()).Run win
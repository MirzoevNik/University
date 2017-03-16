module task3

open System;
// масштабирование
(* from int to float range *)
let scale (a:float,b:float) (i,j) x = 
          float(x-i)/float(j-i)*(b-a)+a;;

(* from float range to int *)
let uscale (i,j) (a:float,b:float) (f:float) =  
            int((f-a)/(b-a)*float(j-i))+i;;
// количество точек на экране под х и у
let xrange = (0,50)
let yrange = (0,15)
let plot xdim ydim f =
// построчное построение графика
  for i=snd yrange downto fst yrange do
    for j=fst xrange to snd xrange do
      let x = scale xdim xrange j
      let y = uscale yrange ydim (f x)
      Console.Write(if y=i then "*" else " ")
    Console.WriteLine("")

let plotReverse xdim ydim f =
// построчное построение графика
  for i=fst yrange to snd yrange do
    for j=snd xrange downto fst xrange do
      let x = scale xdim xrange j
      let y = uscale yrange ydim (f x)
      Console.Write(if y=i then "*" else " ")
    Console.WriteLine("")
// x от -4 до 4, у от -1 до 5, функция
plot (-2.0,4.0) (-1.0,20.0) (fun x -> sqrt x - 6.0 * cos x + 5.0 * sin x)
plotReverse (-2.0,4.0) (-1.0,20.0) (fun x -> sqrt x - 6.0 * cos x + 5.0 * sin x)
let s = Console.ReadKey()



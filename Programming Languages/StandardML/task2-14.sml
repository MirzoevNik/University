(* N - целочисленный параметр *)
fun y N =
  let
    val rN = real N

    (* Внутренний цикл (сумма): подсчет i-го слагаемого
     * домножение на j-й множитель результата slag *)
    fun jIter (i, j, slag) =
      if j > rN 
      then slag
      else jIter (i, j + 1.0, slag + Math.log10 i + i / j);

    (* Внешний цикл (сумма):
     * добавление i-го слагаемого (при i<=N) к результату rez *)
    fun iIter (i, rez) =
      if i > rN 
      then rez
      else iIter (i + 1.0, rez + jIter (i, 1.0, 0.0));
  in
    (* Запускается цикл по i (сумма) от 1.0  *)
    iIter (1.0, 0.0)
  end
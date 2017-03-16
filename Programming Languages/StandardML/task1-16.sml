fun f (x : int) : real =
  let
    val A = real (x * x) + 5.0
    val B = real (x * x * x) - 3.0
    val C = real x + 7.0
  in
    (A * A - B * B) / C + C * C / A + B
  end
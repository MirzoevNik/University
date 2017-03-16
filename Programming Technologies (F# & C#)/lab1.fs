// 1
let fun1 x = x |> (fun x -> x + 5) |> (fun x -> x * 20)

// 2
let rec K (n : int) = if (n < 10) then 1 else K (n / 10) + 1
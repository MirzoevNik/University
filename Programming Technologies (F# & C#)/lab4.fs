// 1
let fun1 list x = List.map (fun y -> (-x) * y) list

// 2
let fun2 x y = 
    List.map (fun n -> n - x) (List.filter (fun n -> n % 3 = 0) [15 .. -1 .. 1])
        @ List.map (fun n -> n * y) (List.filter (fun n -> n % 2 = 0) [15 .. -1 .. 1])
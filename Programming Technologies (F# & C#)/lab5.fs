// 1
let fun1 x = 
    [| 20 .. -1 .. 1 |]
     |> Array.choose (fun n -> if (n % 2 = 1 && n % 3 <> 0) then
                                   Some (n + x)
                               else
                                   None)
     |> Array.rev

// 2 
let fun2 =
    let array = Array.sub (Array.sub (Array.sub [| 5 .. 150 |] 3 90) 5 30) 4 4
    let printArray (arr : int[]) =
        for i in 0 .. arr.Length - 1 do
            printf "%d " (Array.get arr i)
        printfn ""
    printfn "Elements:"
    printArray array
    printfn "Count of elements: %d" (Array.length array)
    printfn "An array after sorting descending:"
    printArray (Array.sortBy (fun n -> - (abs n)) array)
    printfn "New array:"
    printArray (Array.choose (fun n -> if (n % 2 = 1 && n % 5 = 0) then
                                           None
                                       else
                                           Some n) array)
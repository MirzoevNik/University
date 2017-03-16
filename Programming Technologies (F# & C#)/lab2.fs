// 1 
let fun11 x = 
    for i in seq {1 .. 100} do
        if (i % 5 = 0) then 
            printf "%d " (i * x)
    printfn ""

let fun12 x = 
    for i = 1 to 100 do
        if (i % 5 = 0) then 
            printf "%d " (i * x)
    printfn ""

let fun13 x =
    let mutable i = 0
    while (i <= 100) do
        i <- i + 1
        if (i % 5 = 0) then 
            printf "%d " (i * x)
    printfn ""

// 2
let fun2 = 
    let mutable count = -2
    for _ in 100 .. -3 .. 1 do
        count <- count + 3
    printfn "Number of elements in list: %d" count

// 3
let fun3 (x : float) =
    if x < 0.0 then
        (abs x) ** (1.0 / 3.0)
    else if x < 1.0 then
        -2.0 * x + x / (1.0 + x)
    else
        abs (3.0 - x) / (1.0 + x)

// 4
let fun4 x = 
    let first = x / 1000
    let second = (x % 1000) / 100
    let third = (x % 100) / 10
    let fourth = x % 10
    ((first * second * third * fourth) % 10) * 1000 +
        ((second * third) % first) * 100 +
        ((first + second + third + fourth) % fourth) * 10 +
        abs(second - third) % 10

// 5
let denial x = not x
let conjunction x y = x && y
let disjunction x y = x || y
let following x y = not x || y
let equivalence x y = x && y || (not x) && (not y)
let exclusiveOr x y = (not x) && y || x && (not y)

let fun5 a b c = 
    following (conjunction a b) 
        (equivalence (denial a) (disjunction b c))

let printFun5 =
    printfn "   A   |   B   |   C   |  fun  "
    printfn "-------+-------+-------+-------"
    printfn " false | false | false | %5b " (fun5 false false false)
    printfn " false | false | true  | %5b " (fun5 false false true)
    printfn " false | true  | false | %5b " (fun5 false true false)
    printfn " false | true  | true  | %5b " (fun5 false true true)
    printfn " true  | false | false | %5b " (fun5 true false false)
    printfn " true  | false | true  | %5b " (fun5 true false true)
    printfn " true  | true  | false | %5b " (fun5 true true false)
    printfn " true  | true  | true  | %5b " (fun5 true true true)
    printfn ""
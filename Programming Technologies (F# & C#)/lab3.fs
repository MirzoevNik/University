// 1
let length (x, y) = sqrt (float (x * x + y * y))

// 2
type Product = {
    Name : string
    Model : string
    mutable Price : int
}

let product1 = {Name = "PastaMasta"; Model = "Pasta"; Price = 38}
let product2 = {Name = "NiceRice"; Model = "Rice"; Price = 46}
let product3 = {Name = "Potatato"; Model = "Potato"; Price = 25}
let product4 = {Name = "FlyingChicken"; Model = "Chicken"; Price = 99}
let product5 = {Name = "CandyShop"; Model = "Candy"; Price = 50}

let printPrice product = printfn "Product %s has price: %d" product.Name product.Price
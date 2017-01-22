def f(x, v):
    return v * (x ** 3)

def derivative(x, v):
    return 3 * v * (x ** 2) + v * (x ** 3) - f(x, v)

def dif(x, v):
    return abs(f(x, v) - derivative(x, v))

def taskResolve():
    size = 11
    x = [0.0] * size
    for i in range(size):
        x[i] = i + 1

    v = 5

    y = [0.0] * size
    yt = [0.0] * size
    e = [0.0] * size
    for i in range(size):
        y[i] = f(x[i], v)
        yt[i] = derivative(x[i], v)
        e[i] = dif(x[i], v)
        
    print(x)
    print(y)
    print(yt)
    print(e)
    
taskResolve()
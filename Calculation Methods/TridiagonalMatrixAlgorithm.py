def tdma(a, b):
    size = len(a)
    alpha = [0.0] * size
    beta = [0.0] * size
    
    alpha[1] = -a[0][1] / a[0][0]
    beta[1] = b[0] / a[0][0]
    for i in range(2, size):
        m = a[i - 1][i - 1] + a[i - 1][i - 2] * alpha[i - 1]
        alpha[i] = -a[i - 1][i] / m
        beta[i] = (-a[i - 1][i - 2] * beta[i - 1] + b[i - 1]) / m
        
    listX = [0.0] * size
    listX[size - 1] = (-a[size - 1][size - 2] * beta[size - 1] + b[size - 1]) / (a[size - 1][size - 1] + a[size - 1][size - 2] * alpha[size - 1])
    
    for i in reversed(range(size - 1)):
        listX[i] = alpha[i + 1] * listX[i + 1] + beta[i + 1]
    return listX

def taskResolve():
    a = [[1.0, 2.0, 0.0, 0.0],
         [1.0, 3.0, 1.0, 0.0],
         [0.0, 1.0, 3.0, 1.0],
         [0.0, 0.0, 1.0, 5.0]]
    b = [3.0, 5.0, 5.0, 6.0]
    
    print(a)
    print(b)
 
    xs = tdma(a, b)
    print("Answer:", end="\n")
    print(xs)
    
taskResolve()
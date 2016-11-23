def det(a):
    d = 1.0
    for i in range(len(a)):
        d *= a[i][i]
    return d
 
def swapRows(rows, row1, row2):
    t = rows[row1]
    rows[row1] = rows[row2]
    rows[row2] = t
 
def toSpeedMatrix(a, b):
    size = len(a)
    mat = [[0.0] * size] * size
 
    for i in range(size - 1):
        for j in range(i + 1, size):
            mat[j][i] = a[j][i] / a[i][i]
            b[j] -= mat[j][i] * b[i]
            for k in range(i, size):
                a[j][k] -= mat[j][i] * a[i][i]
 
def sumOfOtherXs(listX, a, k):
    res = 0.0
    for i in range(k, len(a)):
        res += a[k][i] * listX[i]
    return res
 
def reverse(listX, a, b):
    size = len(a)
    listX[size - 1] = b[size - 1] / a[size - 1][size - 1]
    for i in reversed(range(size - 1)):
        listX[i] = (b[i] - sumOfOtherXs(listX, a, i)) / a[i][i]
 
def gauss(a, b):
    size = len(a)
    listX = [0.0] * size
    for i in range(size):
        maxElement = a[i][i]
        curRow = i
        for j in range(i, size):
            if a[j][i] > maxElement:
                maxElement = a[j][i]
                curRow = j
        if maxElement == 0.0:
            raise ValueError('Max element is 0')
        if curRow != i:
            swapRows(a, i, curRow)
            swapRows(b, i, curRow)
 
    toSpeedMatrix(a, b)
    reverse(listX, a, b)
    return listX
 
def taskResolve():
    a = [[1.0, 2.0, 1.0],
         [0.0, 1.0, 1.0],
         [0.0, 0.0, 1.0]]
    b = [4.0, 2.0, 1.0]
 
    xs = gauss(a, b)
    print(a)
    print(xs)
    
taskResolve()
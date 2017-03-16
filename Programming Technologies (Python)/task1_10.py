# 1
n, m = map(int, input().split())
mas = [[int(j) for j in input().split()] for i in range(n)]
maxValue = mas[0][0]
maxI = maxJ = 0
for i in range(n):
    for j in range(m):
        if mas[i][j] > maxValue:
            maxValue = mas[i][j]
            maxI = i
            maxJ = j
print(maxI, maxJ)

# 2
n = int(input())
mas = [["."] * n for i in range(n)]
for i in range(n):
    mas[i][n // 2] = "*"
    mas[n // 2][i] = "*"
    mas[i][i] = "*"
    mas[i][n - i - 1] = "*"
for row in mas:
    print(' '.join([str(elem) for elem in row]))
    
# 3
n, m = map(int, input().split())
mas = []
for i in range(n):
    mas.append([])
    for j in range(m):
        if (i + j) % 2 != 0:
            mas[i].append("*")
        else:
            mas[i].append(".")
for row in mas:
    print(' '.join([str(elem) for elem in row]))
    
# 4
n = int(input())
mas = [[abs(i - j) for j in range(n)] for i in range(n)]
for row in mas:
    print(' '.join([str(elem) for elem in row]))
    
# 5
n = int(input())
mas = [[0] * (n - i - 1) + [1] + [2] * i for i in range(n)]
for row in mas:
    print(' '.join([str(elem) for elem in row]))
    
# 6
def swapColumns(mas, i , j):
    for k in range(len(mas)):
        x = mas[k][i]
        mas[k][i] = mas[k][j]
        mas[k][j] = x
    return mas

n, m = map(int, input().split())
mas = [[int(j) for j in input().split()] for i in range(n)]
i, j = map(int, input().split())
for row in swapColumns(mas, i, j):
    print(' '.join([str(elem) for elem in row]))
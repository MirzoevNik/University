# 1
a = int(input())
b = int(input())
for x in range(a + a % 2 - 1, b - 1, -2):
    print(x, end = ' ')
    
# 2
n = int(input())
summa = 0
f = 1
for i in range(1, n + 1):
    f *= i
    summa += f
print(summa)

# 3
n = int(input())
count = 0
for i in range(n):
    x = int(input())
    if x == 0:
        count += 1
print(count)

# 4
n = int(input())
for i in range(1, n + 1):
    for j in range(1, i + 1):
        print(j, end = '')
    print(end = '\n')
    
# 5
n = int(input())
summa = 0
for x in range(1, n + 1):
    summa += x
for i in range(n - 1):
    summa -= int(input())
print(summa)

# 6
n = 9
for i in range(n + 1):
    for j in range(n, n - i, -1):
        print(j, end = ' ')
    print(0, end = '\n')
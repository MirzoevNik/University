# 1
mas = input().split()
for i in range(0, len(mas), 2):
    print(mas[i], end = ' ')
    
# 2
mas = [int(x) for x in input().split()]
for x in mas:
    if x % 2 == 0:
        print(x, end = ' ')
        
# 3
mas = [int(x) for x in input().split()]
for i in range(1, len(mas)):
    if mas[i] > mas[i - 1]:
        print(mas[i], end = ' ')
        
# 4
mas = [int(x) for x in input().split()]
for i in range(1, len(mas)):
    if mas[i] < 0 and mas[i - 1] < 0 or mas[i] > 0 and mas[i - 1] > 0:
        print(mas[i - 1], mas[i])
        break
        
# 5
mas = [int(x) for x in input().split()]
x = int(input())
for i in range(len(mas) + 1):
    if i == len(mas) or x > mas[i]:
        print(i + 1)
        break     
        
# 6
mas = [int(x) for x in input().split()]
i = 0
while i + 1 < len(mas):
    mas[i], mas[i + 1] = mas[i + 1], mas[i]
    i += 2
print(' '.join([str(x) for x in mas]))

# 7
mas = [int(x) for x in input().split()]
k = int(input())
for i in range(k, len(mas) - 1):
    mas[i] = mas[i + 1]
mas.pop()
print(' '.join([str(x) for x in mas]))

# 8
mas = [int(x) for x in input().split()]
k, c = map(int, input().split())
mas.append(mas[len(mas) - 1])
for i in range(len(mas) - 1, k, -1):
    mas[i] = mas[i - 1]
mas[k] = c
print(' '.join([str(x) for x in mas]))

# 9
n = 8
x = [0] * n
y = [0] * n
for i in range(n):
    x[i], y[i] = map(int, input().split())
result = 'NO'
for i in range(n - 1):
    x1, y1 = x[i], y[i]
    for j in range(i + 1, n):
        x2, y2 = x[j], y[j]
        if x1 == x2 or y1 == y2 or abs(x1 - x2) == abs(y1 - y2):
            result = 'YES'
            break
print(result)
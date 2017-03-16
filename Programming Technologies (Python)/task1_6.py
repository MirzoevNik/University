# 1
n = int(input())
x = 2
while n % x != 0:
    x += 1
print(x)

# 2
x = int(input()) * 100
p = int(input())
y = int(input()) * 100
count = 0 
while x < y:
    x += x * p // 100
    count += 1
print(count)

# 3
count = 0
while int(input()) != 0:
    count += 1
print(count)

# 4
s = 0
count = 0
x = int(input())
while x != 0:
    s += x
    count += 1
    x = int(input())
print(s / count)

# 5
count = 0
m = x = int(input())
while x != 0:
    if x == m:
        count += 1
    elif x > m:
        count = 1
        m = x
    x = int(input())
print(count)

# 6
max1 = max2 = 0
x = int(input())
while x != 0:
    if max1 == 0:
        max1 = x
    elif x > max1:
        max2 = max1
        max1 = x
    elif x > max2:
        max2 = x
    x = int(input())
print(max2)

# 7
a = int(input())
if a == 0:
    print(0)
elif a == 1:
    print(1)
else:
    n = 2
    fibPrev = 1
    fibPrevPrev = 0
    fibCur = fibPrev + fibPrevPrev
    while fibCur < a:
        fibPrevPrev, fibPrev = fibPrev, fibCur
        fibCur = fibPrev + fibPrevPrev
        n += 1
    if fibCur == a:
        print(n)
    else:
        print(-1)
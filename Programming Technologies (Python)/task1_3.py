from math import *

# 1
x = int(input())
print(x % 10)

# 2
x = float(input())
print(int(x * 10) % 10)

# 3
h = int(input())
a = int(input())
b = int(input())
print(ceil((h - b) / (a - b)))

# 4
x = float(input())
result = int(x)
if int(x * 10) % 10 > 4:
    result += 1
print(result)

# 5
p = int(input())
x = int(input())
y = int(input())
value = int((x + 0.01 * y) * (1. + p / 100.) * 100)
print(value // 100, value % 100)
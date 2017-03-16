# 1
a = int(input())
b = int(input())
c = int(input())
print(a + b + c)

# 2
b = int(input())
h = int(input())
print(b * h * 1 / 2)

# 3
n = int(input())
k = int(input())
print(k // n)
print(k % n)

# 4
n = int(input())
n %= 24 * 60
print(n // 60, n % 60)

# 5
user = input()
print("Hello, ", user, "!", sep='')

# 6
number = int(input())
print('The next number for the number ', number, ' is ', number + 1, '.', sep='')
print('The previous number for the number ', number, ' is ', number - 1, '.', sep='')

# 7
count1 = int(input())
count2 = int(input())
count3 = int(input())
print((count1 + 1) // 2 + (count2 + 1) // 2 + (count3 + 1) // 2)

# 8
a = int(input())
b = int(input())
l = int(input())
n = int(input())
print((l + n * a + (n - 1) * b) * 2 - a)
# 1
s = input()
print(s[2])
print(s[-2])
print(s[:5])
print(s[:-2])
print(s[::2])
print(s[1::2])
print(s[::-1])
print(s[::-2])
print(len(s))

# 2
print(input().count(' ') + 1)

# 3
s = input()
x = len(s) // 2 + len(s) % 2
print(s[x:len(s)], s[:x], sep = '')

# 4
s = input()
x, y = s.find('f'), s.rfind('f')
if x != y:
    print(x, y)
elif x != -1:
    print(x)
    
# 5
s = input()
symbol = 'h'
print(s.replace(s[s.find(symbol) : s.rfind(symbol) + 1], ''))

# 6
s = input()
symbol = 'h'
x, y = s.find(symbol), s.rfind(symbol)
s = s[:x] + s[y : x : -1] + s[y:]
print(s)

# 7
print(input().replace('1', 'one'))

# 8
s = input()
print(s.replace('h', 'H', s.count('h') - 1).replace('H', 'h', 1))

# 9
s = input()
res = ""
for i in range(len(s)):
    if i % 3 != 0:
        res += s[i]
print(res)
# 1
print(len(set(input().split())))

# 2
print(len(set(input().split()) & set(input().split())))

# 3
print(*sorted(set(input().split()) & set(input().split()), key = int))

# 4
s = set()
for x in input().split():
    if x in s:
        print('YES')
    else:
        print('NO')
    s.add(x)

# 5
def printSet(_set):
    print(len(_set))
    print(*sorted(_set))

n, m = map(int, input().split())
set1 = set()
for i in range(n):
    set1.add(int(input()))
set2 = set()
for i in range(m):
    set2.add(int(input()))
printSet(set1 & set2)
printSet(set1 - set2)
printSet(set2 - set1)

# 6
words = set()
for i in range(int(input())):
    words |= set(input().split())
print(len(words))
# 1
x = int(input())
y = int(input())
if x < y:
	print(x)
else:
	print(y)
	
# 2
x = int(input())
if x < 0:
	print(-1)
elif x > 0:
	print(1)
else:
	print(0)
    
# 3
point1X = int(input())
point1Y = int(input())
point2X = int(input())
point2Y = int(input())
if (point1X + point1Y) % 2 == (point2X + point2Y) % 2:
    print('YES')
else:
    print('NO')
    
# 4
year = int(input())
if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
    print('YES')
else:
    print('NO')
    
# 5
x = int(input())
y = int(input())
z = int(input())
minValue = x
if y < minValue:
    minValue = y
if z < minValue:
    minValue = z
print(minValue)

# 6
x = int(input())
y = int(input())
z = int(input())
count = 0
if x == y:
    count += 2
    if x == z:
        count += 1
elif x == z or z == y:
    count = 2
print(count)

# 7
point1X = int(input())
point1Y = int(input())
point2X = int(input())
point2Y = int(input())
if point1X == point2X or point1Y == point2Y:
    print('YES')
else:
    print('NO')
    
# 8
point1X = int(input())
point1Y = int(input())
point2X = int(input())
point2Y = int(input())
if abs(point1X - point2X) < 2 and abs(point1Y - point2Y) < 2:
    print('YES')
else:
    print('NO')
    
# 9
point1X = int(input())
point1Y = int(input())
point2X = int(input())
point2Y = int(input())
if abs(point1X - point2X) == abs(point1Y - point2Y):
    print('YES')
else:
    print('NO')
    
# 10
point1X = int(input())
point1Y = int(input())
point2X = int(input())
point2Y = int(input())
if point1X == point2X or point1Y == point2Y or abs(point1X - point2X) == abs(point1Y - point2Y):
    print('YES')
else:
    print('NO')
import math

def f(x):
	return x ** 4

def lagrange(listX, listF, x_i):
	n = len(listX)
	L = 0.0
	for k in range(n):
		summand = listF[k]
		for i in range(n):
			if i != k:
				summand *= (x_i - listX[i]) / (listX[k] - listX[i])
		L += summand
	return L

def taskResolve():
	startSegment = float(input("Enter the start of the segment: "))
	endSegment = float(input("Enter the end of the segment: "))
    
	print("\n\n\nResult:\n\n")
    
	count = 5
	step = (endSegment - startSegment + 1) / count

	listX = [0] * count
	listF = [0.0] * count
	x = startSegment
	i = 0
	while (x <= endSegment):
		result = f(x)
		listX[i] = x
		listF[i] = result
		x += step
		i += 1
		
	for i in range(count):
		if (i > 0):
			x_i = (listX[i - 1] + listX[i]) / 2.0
			print("({0}, {1})".format(x_i, lagrange(listX, listF, x_i)))
		print(listX[i], end = '\t')
		print(listF[i], end = '\n')
        
taskResolve()
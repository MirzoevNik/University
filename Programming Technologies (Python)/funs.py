from math import sqrt, cos, sin

# 1.1.3
def polynomialHermite(x, n):
	if n == 0:
		return 1
	if n == 1:
		return 2 * x
	hPrevPrev = 1
	hPrev = 2 * x
	i, h = 2, hPrev
	while i <= n:
		h = 2 * x * hPrev - 2 * (i - 1) * hPrevPrev
		hPrevPrev, hPrev = hPrev, h
		i += 1
	return round(h, 2)
	
# 1.1.14
def s(n):
	if n == 1:
		return 1
	i, result = n - 1, sqrt(1 + n)
	while i > 1:
		result = sqrt(1 + i * result)
		i -= 1
	return round(result, 2)
	
# 1.2.7
def printPoints(r):
	for i in range(1, r + 1):
		for j in range(1, r + 1):
			for k in range(1, r + 1):
				if i * i + j * j + k * k <= r:
					print(i, j, k)
	
# 1.2.18
def printStarts(n):
	k = 0
	for i in range(n, 0, -2):
		for j in range(k):
			print(' ', end = '')
		for j in range(i):
			print('*', end = '')
		k += 1
		print()
		
# 1.3.8
def polynomialLaguerre(x, k, n):
	if n == 0:
		return 1
	if n == 1:
		return x - (k + 1)
	return round((x - k - 2 * n - 3) * polynomialLaguerre(x, k, n - 1) - (n - 1) * (k + n - 1) * polynomialLaguerre(x, k, n - 2), 2)
	
# 1.3.13
def methodDichotomy(a, b, eps):
	while abs(b - a) > eps:
		x = (a + b) / 2
		if x == 0:
			x = eps
		if a == 0:
			a = eps
		if b == 0:
			b = eps
		if f(x) * f(b) < 0:
			a = x
		else:
			b = x
	return round((a + b) / 2, 4)
	
def f(x):
	return cos(2 / x) - 2 * sin(1 / x) + 1 / x
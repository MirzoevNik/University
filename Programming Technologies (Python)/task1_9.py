from collections import defaultdict

# 1
words = input().split()
dictWords = {}
for word in words:
	if word in dictWords:
		dictWords[word] += 1
	else:
		dictWords[word] = 0
	print(dictWords[word], end = ' ')
	
# 2
dictWords = {}
for i in range(int(input())):
	key, value = input().split()
	dictWords[key] = value
word = input()
for key, value in dictWords.items():
	if word == key:
		print(value)
	elif word == value:
		print(key)
		
# 3
candidates = {}
for i in range(int(input())):
	name, value = input().split()
	if name in candidates:
		candidates[name] += int(value)
	else:
		candidates[name] = int(value)
for name in sorted(candidates.keys()):
    print(name, candidates[name])
	
# 4
dictWords = {}
maxCount = 0
for i in range(int(input())):
	words = input().split()
	for word in words:
		if word in dictWords:
			dictWords[word] += 1
			if dictWords[word] > maxCount:
				maxCount = dictWords[word]
		else:
			dictWords[word] = 0
wordsList = []
for word, count in dictWords.items():
	if count == maxCount:
		wordsList.append(word)
print(min(wordsList))

# 5
operations = {'write' : 'W', 'read' : 'R',  'execute' : 'X'}
files = {}
for i in range(int(input())):
	fileName, *operationList = input().split()
	files[fileName] = set(operationList)
for i in range(int(input())):
	operation, fileName = input().split()
	if operations[operation] in files[fileName]:
		print('OK')
	else:
		print('Access denied')

# 6
dictWords = defaultdict(lambda: 0)
for i in range(int(input())):
	words = input().split()
	for word in words:
		dictWords[word] += 1
pairs = defaultdict(lambda: [])
for word, frequency in sorted(dictWords.items()):
	pairs[frequency].append(word)
for _, words in sorted(pairs.items(), reverse=True):
	for word in words:
		print(word)

# 7
dictCities = {}
for i in range(int(input())):
    country, *cities = input().split()
    for city in cities:
        dictCities[city] = country
for i in range(int(input())):
    print(dictCities[input()])
	
# 10
dictSales = defaultdict(lambda: defaultdict(int))
while True:
	try:
		customer, product, count = input().split()
		dictSales[customer][product] += int(count)
	except Exception:
		break
for customer, dictProducts in sorted(dictSales.items()):
	print(customer + ':')
	for product, count in sorted(dictProducts.items()):
		print(product, count)
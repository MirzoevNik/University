import math

def function(x, n):
    return math.sin(x / (2.0 ** n))

def functionalSeries(x, eps):
    partialSum = 0.0
    
    n = 0
    summand = function(x, n)
    while (abs(summand) >= eps):
        partialSum += summand
        n += 1
        summand = function(x, n)
        
    return (partialSum, n)

def taskResolve():
    startSegment = float(input("Enter the start of the segment: "))
    endSegment = float(input("Enter the end of the segment: "))
    
    print("\n\n\nResult:\n\n")
    
    eps = 10 ** (-8)
    step = (endSegment - startSegment) / 10.0
    x = startSegment
    result = functionalSeries(x, eps)
    while (x <= endSegment):
        prevResult = result[0]
        result = functionalSeries(x, eps)
        if (x > startSegment):
            print("({0}, {1})".format((x + x - step) / 2.0, (prevResult + result[0]) / 2.0))
        print(x, end = '\t')
        print(result[0], end = '\t')
        print(result[1], end = '\n')
        x += step
        
taskResolve()
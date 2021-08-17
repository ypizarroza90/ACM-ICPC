__author__ = 'pizarroza'
from sys import stdin
import math

def line():
    return stdin.readline().strip()

power = []

def SUM(n):
    return n*(n+1)*(n+2)/6.0

def solve(n):
    temp = n//2
    impar = (temp)+8.0*SUM(temp-1)
    if n & 1:
        temp = n//2 +1
        impar = (temp)+8.0*SUM(temp-1)
        sumaP = n*(n+1)*(2*n+1)/6.0
        sumaP -= impar
        return 2*sumaP
    else:
        return 2*impar
while True:
    n = int(line())
    if n == 0:
        break
    print(format(math.sqrt(solve(n)/float(n-1)),'.6f'))

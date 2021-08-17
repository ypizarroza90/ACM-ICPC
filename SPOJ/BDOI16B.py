__author__ = 'pizarroza'
from sys import stdin
 
 
def line():
    return stdin.readline().strip()
 
def factorize(n):
    factors = {}
    d = 2
    while n > 1:
        power = 0
        while n % d == 0:
            power += 1
            n //= d
        if power > 0:
            factors[d] = power
        d += 1
        if d * d > n:
            d = n
    return factors
 
def factpow(n,k):
    ans = 0;
    while n>0:
        ans += n//k
        n//=k
    return ans
 
def solve(n,k):
    fact = factorize(k)
    lista = []
    for x,y in fact.items():
        lista.append(factpow(n,x)//y)
 
    return min(lista)
 
 
 
if __name__ == "__main__":
    cas = int(line())
    for i in range(cas):
        a,b = map(int, line().split())
        print 'Case', str(i+1)+':',solve(a, b)
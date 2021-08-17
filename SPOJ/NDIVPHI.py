from sys import stdin
from bisect import bisect_right,bisect_left

def line():
    return stdin.readline().strip()

MAX = 2 * (10 ** 2) + 1
SQRT = 20
primes = []
flag = [0] * ((10 ** 3) >> 6)


def ifc(x):
    return flag[x >> 6] & (1 << ((x >> 1) & 31))


def isc(x):
    flag[x >> 6] |= (1 << ((x >> 1) & 31))


def criba():
    for i in range(3 , SQRT , 2):
        if ifc(i) == 0:
            for j in range(i * i , MAX , i << 1):
                isc(j)
    primes.append(1) # not prime
    primes.append(2)
    for i in range(3 , MAX , 2):
        if ifc(i) == 0:
            last = primes[-1]
            primes.append(i*last)

if __name__ == "__main__":
    criba()
    for i in range(20):
        n = int(line())
        ans = bisect_right(primes,n)
        print(primes[ans-1])
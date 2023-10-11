import functools
from sys import stdin
from random import randrange
from math import gcd


def line():
return stdin.readline().strip()

def memoize(function):
cache = {}
@functools.wraps(function)
def memoized(*args):
    if args in cache:
        return cache[args]
    else:
        res = function(*args)
        cache[args] = res
        return res
return memoized


def miller_rabin(n, k=20):
if n == 2:
    return True
if not n & 1:
    return False

def check(a, s, d, n):
    x = pow(a, d, n)
    if x == 1:
        return True
    for i in range(s - 1):
        if x == n - 1:
            return True
        x = pow(x, 2, n)
    return x == n - 1

s = 0
d = n - 1
while d % 2 == 0:
    d >>= 1
    s += 1

for i in range(k):
    a = randrange(2, n)
    if not check(a, s, d, n):
        return False
return True


def rho(n):
if miller_rabin(n):
    return n

if not n & 1:
    return 2

def function(x, n):
    return (pow(x, 2, n)+1) % n

for i in range(20):
    x = i
    y = function(x, n)
    p = gcd((y-x+n) % n, n)
    while p == 1:
        x = function(x, n)
        y = function(function(y, n), n)
        p = gcd((y-x+n) % n, n)
    if p == 0 or p == n:
        continue
    return p


factors = []


def factor(n):
if n == 1:
    return
if miller_rabin(n):
    if n not in factors: factors.append(n)
    return
x = rho(n)
factor(x)
factor(n//x)

@memoize
def phi(N):
factors.clear()
factor(N)
ans = N
for div in factors:
    ans -= ans//div
return ans

@memoize
def solve(N, K):
if K == 1:
    return phi(N)
if N == 1:
    return N
return solve(phi(N), K-1)

if __name__ == "__main__":
N, K = map(int, line().split())
print(solve(N, K))

from sys import stdin

def line():
    return stdin.readline().strip()

MAX = 2 *(10 ** 2) + 1
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
    primes.append(2)
    for i in range(3 , MAX , 2):
        if ifc(i) == 0:
            primes.append(i)


def factpow(N, k):
    ans = 0
    while N > 0:
        ans += N // k
        N //= k

    return ans

def numdiv(N):
    ans = 1
    pos = 0
    while primes[pos] <= N:
        ans *= factpow(N, primes[pos]) + 1
        pos += 1
    return ans
if __name__ == "__main__":
    criba()
    n = int(line())
    divs = [1]
    i = 1
    while numdiv(i) < 10 ** 19:
        divs.append(numdiv(i))
        i += 1
    for _ in range(n):
        N = int(line())
        lo,hi = 0, min(N,len(divs))
        while lo <= hi:
            mid = (lo+hi)>>1
            ans = divs[mid]
            if ans > N:
                hi = mid-1
            else:
                lo = mid + 1
        print hi if divs[hi]==N or hi > 10 ** 4 else 'nai'
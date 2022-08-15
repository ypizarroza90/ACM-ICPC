from random import randrange
from sys import stdin, stdout


def readline():
    return stdin.readline().strip()


def writeline(value):
    stdout.write(str(value) + "\n")


def miller_rabin(n, k=20):
    if n < 2:
        return False
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


def check(n) -> bool:
    N = str(n)
    l = len(N)
    dp = [-1 for i in range(l)]
    for i in range(l):
        if miller_rabin(int(N[0: i + 1])):
            dp[i] = 1
    for i in range(l):
        for j in range(1, i + 1):
            if dp[j - 1] != -1 and N[j] != '0' and dp[j - 1] + 1 > dp[i]:
                if miller_rabin(int(N[j: i + 1])):
                    dp[i] = dp[j - 1] + 1
    if dp[l - 1] > 1:
        return True
    return False


def next_prime(n) -> int:
    n = (n+1) // 2 * 2 + 1
    while not miller_rabin(n, 10):
        n += 2
    return n

if __name__ == '__main__':
    cas = int(readline())
    while cas > 0:
        n = int(readline())
        while not check(n):
            n = next_prime(n)
        writeline(n)
        cas -= 1

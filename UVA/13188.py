from sys import stdin


def line():
    return stdin.readline().strip()

MOD = 10**9 + 7
inv_six = pow(6, MOD-2, MOD)
inv_two = pow(2, MOD-2, MOD)


def sum_triangular(n):
    return (n*(n+1)*(n+2)*inv_six) % MOD

def solve(n):
    r = n // 2 + n % 2
    c = n // 2 + 1

    suma = sum_triangular(n) - sum_triangular(n-r)
    suma = (suma + MOD) % MOD
    rest = (c * (c-1) * inv_two) % MOD
    suma = (suma * c - (rest*r) + MOD) % MOD

    return suma

if __name__ == "__main__":
    n = int(line())
    for i in range(1,n+1):
        x = int(line())
        print('Case #{0}: {1}'.format(i,solve(x)))

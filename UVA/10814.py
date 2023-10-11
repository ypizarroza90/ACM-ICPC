from sys import stdin
from math import gcd

def line():
    return stdin.readline().strip()


if __name__ == "__main__":
    n = int(line())
    for _ in range(n):
        n, m = map(int, line().split('/'))
        _gcd = gcd(n, m)
        print(f'{n//_gcd} / {m//_gcd}')


from math import sqrt
from sys import stdin


def line():
    return stdin.readline().strip()


if __name__ == "__main__":
    while True:
        n = int(line())
        if not n:
            break
        sqr = int(sqrt(n))
        print('yes' if sqr*sqr == n else 'no')


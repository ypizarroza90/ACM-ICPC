from sys import stdin


def line():
    return stdin.readline().strip()


def solve(n, m):
    n %= 10
    return pow(n, m, 10)


if __name__ == "__main__":
    while True:
        n, m  = map(int, line().split())
        if n == m and n == 0:
            break
        print(solve(n,m))


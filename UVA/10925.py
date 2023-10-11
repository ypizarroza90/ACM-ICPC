from sys import stdin


def line():
    return stdin.readline().strip()


if __name__ == "__main__":
    cas = 1
    while True:
        acum = 0
        n,m = map(int, line().split())
        if not (n + m): break
        for _ in range(n):
            acum += int(line())
        print(f'Bill #{cas} costs {acum}: each friend should pay {acum//m}')
        print()
        cas += 1


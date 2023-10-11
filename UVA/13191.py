from sys import stdin
import subprocess


def line():
    return stdin.readline().strip()


def factor(n: int):
    fact = subprocess.run(
        f"factor {n}", shell=True, stdout=subprocess.PIPE).stdout.split()[1:]
    return list(map(int, fact))


if __name__ == "__main__":
    N = int(line())
    for i in range(N):
        n = int(line())
        print(' '.join([str(i) for i in factor(n)]))

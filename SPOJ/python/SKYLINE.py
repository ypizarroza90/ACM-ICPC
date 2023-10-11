import sys


def line():
    return sys.stdin.readline()


catalan = [0] * 1001

if __name__ == '__main__':
    catalan[0] = catalan[1] = 1
    for i in range(2, 1001):
        for j in range(i):
            catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]) % 1000000
    while True:
        n = int(line())
        if n == 0:
            break
        print(catalan[n])


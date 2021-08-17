from sys import stdin
import heapq

def readline():
    return stdin.readline().strip()


def solve(a, b):
    l = a*(a-1) // 2 if a > 0 else -a*(a-1) // 2
    r = b*(b+1) // 2 if b > 0 else -b*(b+1) // 2
    flag = (a > 0 and b > 0) or (a < 0 and b < 0)
    if abs(l) > abs(r):
        l,r = r,l
    if flag:
        return r - l
    else:
        return r + l


if __name__ == '__main__':
    while True:
        line = readline()
        if not line:
            break
        a,b = map(int,line.split())
        if a > b:
            a,b = b,a
        print(solve(a,b))








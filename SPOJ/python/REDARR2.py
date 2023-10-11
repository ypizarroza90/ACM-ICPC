from sys import stdin
import heapq

def readline():
    return stdin.readline().strip()


def solve(arr):
    heapq.heapify(arr)
    sum = 0
    while len(arr) >= 2:
        l = heapq.heappop(arr)
        r = heapq.heappop(arr)
        sum += l+r
        heapq.heappush(arr, l+r)
    return sum



if __name__ == '__main__':
    cas = int(readline())
    for _ in range(cas):
        N = int(readline())
        arr = map(int, readline().split())
        print(solve(list(arr)))
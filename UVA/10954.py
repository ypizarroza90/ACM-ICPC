from sys import stdin
import heapq

def line():
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


if __name__ == "__main__":
    while True:
        n = int(line())
        if not n: break
        values = list(map(int, line().split()))
        print(solve(values))

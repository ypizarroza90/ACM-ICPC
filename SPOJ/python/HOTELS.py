import collections
from sys import stdin


def readline():
    return stdin.readline().strip()


def solve(array, K):
    n = len(array)
    acum = [0]
    for x in array:
        acum.append(acum[-1] + x)

    ans = 0
    queue = collections.deque()
    for j, Aj in enumerate(acum):

        while queue and Aj - acum[queue[0]] > K:
            queue.popleft()

        if queue and Aj - acum[queue[0]]<= K:
            ans = max(ans,  Aj - acum[queue[0]])

        queue.append(j)
    return ans if ans != n+1 else -1


if __name__ == '__main__':
    n,k = map(int, readline().split())
    array = list(map(int, readline().split()))
    ans = solve(array, k)
    print(ans)
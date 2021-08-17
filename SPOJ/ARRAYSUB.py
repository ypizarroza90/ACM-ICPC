from sys import stdin
import functools
 
 
def readline():
    return stdin.readline().strip()
 
 
def solve(arr, N, K):
    deque = []
    ans = []
    for i in range(K):
        while len(deque) and arr[deque[-1]] < arr[i]:
            deque.pop()
        deque.append(i)
    ans.append(deque[0])
    for i in range(K, N):
        while len(deque) and arr[deque[-1]] < arr[i]:
            deque.pop()
        while len(deque) and deque[0] <= i- K:
            deque.pop(0)
        deque.append(i)
        ans.append(deque[0])
 
    return ans
 
if __name__ == '__main__':
    n = int(readline())
    array = list(map(int, readline().split()))
    k = int(readline())
    ans = solve(array, n , k)
    for i in ans:
        print(array[i], end=' ') 
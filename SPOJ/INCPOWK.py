from sys import stdin
import functools
 
 
def readline():
    return stdin.readline().strip()
 
def solve(N, K):
	pos,ans = 0, 0
	while N>0:
		ans += k**pos if N % 2 else 0
		N //= 2
		pos += 1 
	return ans 
 
 
if __name__ == '__main__':
	T = int(readline())
 
	for _ in range(T):
		k,n = map(int, readline().split())
		print(solve(n,k)) 
from sys import stdin

def readline():
	return stdin.readline().strip()


def solve(a):
	res = a
	i = 2
	num_div = 1
	while i*i <= a:
	    if a % i == 0:
			res -= res//i
			count = 0
		while a % i == 0:
		    a //= i
		    count += 1
		num_div *= (count+1)
	    i = i+1
	if a > 1:
	    num_div *= 2
	if(a>1):
	    res -= res//a
	return res, num_div


if __name__ == '__main__':
cas = int(readline())
for _ in range(cas):
    n = int(readline())
    a,b = solve(n)
    print(n - a -b + 1)

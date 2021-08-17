__author__ = '@Anthrax'
from sys import stdin

def line():
	return stdin.readline().strip()

if __name__ == '__main__':
	cas  = int(line())
	for i in range(cas):
		a,b,c = map(int,line().split())
		t ,s = 0,1
		if a > c:
			print(0)
		else:
			while s < c // a:
				s *= b
				if s <= c // a:
					t += 1
			print(t)		

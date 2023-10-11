import sys
from math import sqrt
 
 
def line():
    return sys.stdin.readline()
 
 
if __name__ == '__main__':
    cas = int(line())
    mod = 1000000007
    for i in range(cas):
        n = int(line())-1
        ans = (n+2)*pow(2, n-1, mod)
 
        print(f'Case {i+1}: {ans % mod}')

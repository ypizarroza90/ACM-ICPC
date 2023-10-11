import sys
from math import sqrt
 
 
def line():
    return sys.stdin.readline()
 
 
if __name__ == '__main__':
    cas = int(line())
    for i in range(cas):
        n = int(line())
        ans = 'Yes' if int(sqrt(n))** 2 == n else 'No'
 
        print(f'Case {i+1}: {ans}')

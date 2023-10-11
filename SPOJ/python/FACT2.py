import subprocess
from sys import stdin
 
 
def line():
    return stdin.readline().strip()
 
 
def factor(n: int):
    fact = subprocess.run(
        f"factor {n}", shell=True, stdout=subprocess.PIPE).stdout.split()[1:]
    return fact
 
 
if __name__ == "__main__":
 
        while True:
            x = int(line())
            if x == 0:
                break
            fact = factor(x)
            factors = {}
            for x in fact:
                factors[x] = factors.get(x, 0) + 1
            for x, y in factors.items():
                print(f'{int(x)}^{y}', end=' ')
            print()
 

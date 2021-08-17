from sys import stdin

def readline():
    return stdin.readline().strip()


def totient(a):
    res = a
    i = 2
    while i*i <= a:
        if a % i == 0:
            res -= res//i
            while a % i == 0:
                a //= i
        i = i+1
    if(a>1):
        res -= res//a
    return res


if __name__ == '__main__':
    cas = int(readline())
    for _ in range(cas):
        a = int(readline())
        print(totient(a))

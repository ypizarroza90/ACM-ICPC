    from random import randrange
    from sys import stdin
     
     
    def readline():
        return stdin.readline().strip()
     
     
    def miller_rabin(n, k=20):
        if n < 2:
            return False
        if n == 2:
            return True
        if not n & 1:
            return False
     
        def check(a, s, d, n):
            x = pow(a, d, n)
            if x == 1:
                return True
            for i in range(s - 1):
                if x == n - 1:
                    return True
                x = pow(x, 2, n)
            return x == n - 1
     
        s = 0
        d = n - 1
        while d % 2 == 0:
            d >>= 1
            s += 1
     
        for i in range(k):
            a = randrange(2, n)
            if not check(a, s, d, n):
                return False
        return True
     
     
    def check(n) -> bool:
        N = str(n)
        for i in N:
            if i not in '2357':
                return False
        return miller_rabin(n, 5)
     
     
    def down(N, i) -> list:
        if N[i] <= '2':
            N.pop(i)
            N[i] = '7'
        elif N[i] == '3':
            N[i] = '2'
        elif N[i] <= '5':
            N[i] = '3'
        elif N[i] <= '7':
            N[i] = '5'
        else:
            N[i] = '7'
        return N
     
    def next_valid(n) -> int:
        N = list(str(n))
        for i in range(len(N)):
            if not N[i] in '2357':
                while N[i] <= '2' and i>0:
                    i -= 1
                if i< 0:
                    i = 0
                N = down(N, i)
                for j in range(i+1, len(N)):
                    N[j] = '7'
                break
     
        return int(''.join(N))
     
    if __name__ == '__main__':
        cas = int(readline())
        for i in range(cas):
            n = int(readline())
            n = next_valid(n)
            while not check(n):
                n -= 2
                n = next_valid(n)
            print(f'Case {i+1}: {n}')
            cas -= 1 

    from random import randrange
    from sys import stdin, stdout
     
     
    def readline():
        return stdin.readline().strip()
     
     
    def writeline(value):
        stdout.write(str(value) + "\n")
     
     
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
     
    if __name__ == '__main__':
        t = int(readline())
        for _ in range(t):
            dp = [0] * 35
            line = '$' + readline()
            l = len(line) - 1
            dp[0] = 1
            for i in range(1, l+1):
                for j in range(1, i+1):
                    if dp[j - 1] == 0:
                        continue
                    added = int(line[j:i + 1])
                    if miller_rabin(added, 10):
                        dp[i] += dp[j - 1]
            writeline(dp[l]) 
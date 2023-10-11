    import subprocess
    from sys import stdin
     
     
    def line():
        return stdin.readline().strip()
     
    if __name__ == "__main__":
        N = int(line())
        for i in range(N):
            n = int(line())
            while n % 2 == 0:
                n //= 2
     
            print('Case {0}: {1}'.format(i+1, n))
     
    from sys import stdin, stdout
     
     
    def readline():
        return stdin.readline().strip()
     
     
    def writeline(value):
        stdout.write(str(value) + "\n")
     
     
     
    if __name__ == '__main__':
        t = int(readline())
        for _ in range(t):
            n = int(readline())
            writeline(pow(2, n-1, 10**9+7)) 
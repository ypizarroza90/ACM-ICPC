from lib2to3.pgen2.grammar import line
from sys import stdin


def read_line():
    return stdin.readline().strip()


class Matriz(object):

    def __init__(self, N):
        self.N = N
        self.M = [[0] * N for i in range(N)]

    def multiply(self, M2):
        res = [[0] * self.N for i in range(self.N)]
        for i in range(self.N):
            for j in range(self.N):
                for k in range(self.N):
                    x = self.M[i][k] * M2[k][j]
                    res[i][j] += x

        return res

    def identity(self):
        size = range(self.N)
        return [[(i == j) * 1 for i in size] for j in size]

    def power(self, pow):
        res = self.identity()
        while pow > 0:
            if pow & 1:
                res = self.multiply(res)
            pow >>= 1
            self.M = self.multiply(self.M)
        return res


if __name__ == "__main__":
    n = int(read_line())
    M = Matriz(2)
    M.M[0] = [0, 1]
    M.M[1] = [1, 1]
    M.M = M.power(n+1)
    print(M.M[1][1])


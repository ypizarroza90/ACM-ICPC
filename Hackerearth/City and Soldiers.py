from sys import stdin


def line():
    return stdin.readline().strip()


class DisjoinSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.level = [1] * n
        self.N = n

    def equal(self, x, y):
        return self.find(x) == self.find(y)

    def find(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)

        if xroot == yroot:
            return

        self.N -= 1

        if self.level[xroot] == self.level[yroot]:
            self.level[yroot] += 1

        self.parent[xroot] = yroot


if __name__ == "__main__":
    n, q = map(int, line().split())
    d = DisjoinSet(n)
    for _ in range(q):
        input = list(map(int, line().split()))
        if input[0] == 1:
            x, y = input[1] - 1, input[2] - 1
            d.join(x, y)
        elif input[0] == 2:
            val = input[1]-1
            parent = d.find(val)
            d.parent[val] = val
            while parent != val:
                parent = d.find(parent)
                d.parent[parent] = val
        else:
            parent = d.find(input[1]-1)
            print(parent+1)

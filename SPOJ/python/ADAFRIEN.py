    from math import sqrt
    from sys import stdin
     
     
    def line():
        return stdin.readline().strip()
     
     
    if __name__ == "__main__":
        n, k = map(int, line().split())
        D = {}
        for _ in range(n):
            name, val = line().split()
            D[name] = D.get(name, 0) + int(val)
     
        values = dict(sorted(D.items(), key=lambda x: x[1], reverse=True))
        ans = 0
        cost = list(values.values())
        for i in range(min(k, len(cost))):
            ans += cost[i]
     
        print(ans)
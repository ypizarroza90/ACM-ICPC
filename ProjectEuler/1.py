def solve(N):
    ans = 0
    for i in range(N):
        if i % 3 == 0 or i % 5 == 0:
            ans += 1
    return ans

if __name__ == "__main__":
    print(solve(1000))

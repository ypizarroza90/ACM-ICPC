def solve(N):
    square_sum = (N * (N+1) * (2*N +1)) //6
    sum_square = ((N* (N+1)) // 2) ** 2
    return sum_square - square_sum

if __name__ == "__main__":
    print(solve(100))

def smallest(N):
    primes = [2, 3, 5, 7, 11, 13, 17, 19]
    ans = 1
    for prime in primes:
        if prime <= N:
            x = prime
            while x <= N:
                ans *= prime
                x *= prime
    return ans

if __name__ == "__main__":
    print(smallest(20))

from sys import stdin


def line():
    return stdin.readline().strip()


def solve(cad):
    stack = []
    ans = True
    for l in cad:
        if l in '([':
            stack.insert(0, l)
        else:
            if stack:
                r = stack.pop(0)
                if r == '(' and l != ')':
                   return False
                elif r == '[' and l != ']':
                    return False
            else:
                ans = False

    if stack:
        ans = False

    return ans

if __name__ == "__main__":
    n = int(line())
    for _ in range(n):
        ans = solve(line())
        print('Yes') if ans else print('No')


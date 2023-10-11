from sys import stdin


def line():
    return stdin.readline().strip()



if __name__ == "__main__":
    cas = int(line())
    for i in range(cas):
        acum = 0.0
        for j in range(12):
            acum += float(line())

        print(i+1,f'${acum/12.0:,.2f}')


import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    N M
    Array (N x M)
    K
    params:
        N   int     0 <  N <= 50
        M   int     0 <  M <= 50
        Array.element 0 or 1
        K   int     0 <= K <= 1,000
    """
    N, M = map(int, stdin.readline().split())

    lamps = list()
    for r in range(N):
        row = stdin.readline().rstrip()
        lamps.append(row)

    K = int(stdin.readline())
    return N, M, lamps, K


def solve():
    N, M, lamps, K = inputs()

    answer = 0

    dicts = dict()
    for row in lamps:
        zeros = 0
        for c in row:
            zeros += 1 - int(c)

        if zeros > K and (K - zeros) % 2 != 0:
            continue

        if row not in dicts:
            dicts.update({row: 0})
        dicts[row] += 1

        answer = max(answer, dicts[row])

    print(answer)


run()

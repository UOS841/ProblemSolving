from sys import stdin


def run(testcase=1):
    for _ in range(int(testcase)):
        solve()


def inputs():
    """
    Input format
    W H
    params:
        W   int     2 <= W <= 100
        H   int     2 <= H <= 100
    """
    W, H = map(int, stdin.readline().split())

    return W, H


def solve():
    NORTH, EAST = 0, 1

    MOD = 100000
    W, H = inputs()

    maps = list(
        [[0 for _ in range(2)] for w in range(W)]  # NORTH OR EAST  # WIDTH
        for h in range(H)  # HEIGHT
    )

    for r in range(H):
        maps[r][0][NORTH] = 1

    for c in range(W):
        maps[0][c][EAST] = 1

    for r in range(1, H):
        for c in range(1, W):
            maps[r][c][NORTH] = maps[r - 1][c][NORTH] + maps[r - 1][c - 1][EAST]
            maps[r][c][EAST] = maps[r - 1][c - 1][EAST] + maps[r][c - 1][EAST]

    print()
    for r in range(H):
        for c in range(W):
            print(sum(maps[r][c]), end=" ")
        print()

    answer = maps[H - 1][W - 1][NORTH] + maps[H - 1][W - 1][EAST]
    print(answer)


run()

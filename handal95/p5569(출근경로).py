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
    NOT_TURNABLE, TURNABLE = 0, 1

    MOD = 100000
    W, H = inputs()
    
    maps = list(
        [
            [
                [
                    0 for _ in range(2) # TURNABLE
                ] for _ in range(2)     # NORTH OR EAST
            ] for w in range(W)     # WIDTH
        ] for h in range(H)         # HEIGHT
    )
    
    for r in range(1, H):
        maps[r][0][NORTH][TURNABLE] = 1

    for c in range(1, W):
        maps[0][c][EAST][TURNABLE] = 1
        
    for r in range(1, H):
        for c in range(1, W):
            maps[r][c][NORTH][TURNABLE] = sum(maps[r - 1][c][NORTH]) % MOD
            maps[r][c][EAST][TURNABLE] = sum(maps[r][c - 1][EAST]) % MOD

            maps[r][c][NORTH][NOT_TURNABLE] = maps[r - 1][c][EAST][TURNABLE]
            maps[r][c][EAST][NOT_TURNABLE] = maps[r][c - 1][NORTH][TURNABLE]
    
    answer = sum(maps[H - 1][W - 1][NORTH]) + sum(maps[H - 1][W - 1][EAST])
    print(answer)

run()

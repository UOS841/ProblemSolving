from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N, K = map(int, stdin.readline().split())

    return N, K


def solve():
    N, K = inputs()


run()

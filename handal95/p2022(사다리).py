import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    x y c
    params:
        x   float     0 <= x
        y   float     0 <= y
        c   float     0 <= z
    """
    L = int(stdin.readline())

    array = list()
    for i in range(5):
        N, M = map(int, stdin.readline().split())

        value = list()
        for _ in range(N):
            v = stdin.readline().rstrip()
            value.append(v.replace("#", "1").replace(".", "0"))
        array.append(value)

    return L, array


def solve():
    L, array = inputs()

    base = ["".rjust(L, "0") for _ in range(L)]
    show2d(base)
    showFrag(array)

    for i in range(5):
        print(len(array[i]))
        print(len(array[i]))

    def dfs(idx, current):

        show2d(array)
        return

    dfs(0, base)


run()

import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    L
    (
        N M
        Array (N x M)
    ) * 5
    params:
        L   int     3 <= L <= 10
        N   int     1 <=  N, M <= L
        M   int     1 <=  N, M <= L
        Array.element '#' or '.' (N x M)
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


def show2d(arr):
    for row in arr:
        print(row)


def showFrag(arr):
    for i in range(5):
        print(f"<{i+1}>")
        show2d(arr[i])


run()

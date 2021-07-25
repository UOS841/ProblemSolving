from sys import stdin
from queue import Queue


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    S
    T

    params:
        S  start word  ( 1 <= len(S) <= 999)
        T  target word ( 2 <= len(T) <= 1000, len(S) < len(T))

    """
    S = stdin.readline().rstrip()
    T = stdin.readline().rstrip()

    return S, T


def solve():
    S, T = inputs()

    count_a = T.count("A")
    count_b = T.count("B")
    print(count_a, count_b)

    q = Queue()
    q.put(S)

    while not q.empty():
        cur = q.get()

        if len(cur) == len(T):
            if cur == T:
                print(1)
                return
        else:
            if cur.count("A") < count_a:
                q.put(f"{cur}A")

            if cur.count("B") < count_b:
                q.put(f"{cur[::-1]}B")

    print(0)


run()

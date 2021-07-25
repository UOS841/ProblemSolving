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
    
    return list(S), list(T)


def solve():
    S, T = inputs()
    
    while len(S) != len(T):
        if T[-1] == "A":
            T.pop()
        else:
            T.pop()
            T = T[::-1]
            
    print(int(S == T))


run()

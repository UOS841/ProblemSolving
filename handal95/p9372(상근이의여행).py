import re
import itertools
from sys import stdin


def run(testcase=1):
    testcase = int(stdin.readline())
    for t in range(testcase):
        solve()


def inputs():
    N, M = map(int, stdin.readline().split())

    nodes = [list() for _ in range(N + 1)]
    for _ in range(M):
        u, v = map(int, stdin.readline().split())
        nodes[u].append(v)
        nodes[v].append(u)
    
    return N, M, nodes


def solve():
    N, K, nodes = inputs()
    
    visits = [False for _ in range(N + 1)]
    
    def dfs(idx, count):
        visits[idx] = True
        
        for j in nodes[idx]:
            if not visits[j]:
                count = dfs(j, count + 1)
        
        return count
    
    answer = dfs(1, 0)
    print(answer)

run()

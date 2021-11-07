import re
import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N = int(stdin.readline())

    nodes = [[] for _ in range(N + 1)]
    for n in range(N - 1):
        node1, node2 = map(int, stdin.readline().split())

        nodes[node2].append(node1)
        nodes[node1].append(node2)

    return N, nodes


def solve():
    N, nodes = inputs()

    # Set Root Nodes
    parents = [0] * (N + 1)
    parents[1] = -1

    queue = [1]
    while len(queue) > 0:
        cur = queue.pop()
        for child in nodes[cur]:
            if parents[child] != 0:
                continue

            parents[child] = cur
            queue.append(child)
    
    answer = ""
    for p in parents[2:]:
        answer += f"{p}\n"
    print(answer)

run()

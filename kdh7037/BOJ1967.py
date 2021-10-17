import sys
from collections import deque

input = sys.stdin.readline
v = int(input())
e = [[] for _ in range(v + 1)]
for _ in range(v - 1):
    a = list(map(int, input().split()))
    e[a[0]].append((a[1], a[2]))
    e[a[1]].append((a[0], a[2]))

def bfs(start):
    visit = [-1 for _ in range(v + 1)]
    q = deque()
    q.append(start)
    visit[start] = 0
    _max = [0, 0]

    while q:
        node = q.popleft()
        for a, b in e[node]:
            if visit[a] == -1:
                visit[a] = visit[node] + b
                q.append(a)
                if _max[0] < visit[a]:
                    _max = visit[a], a
    return _max

distance, node = bfs(1)
distance, node = bfs(node)
print(distance)
import sys
from collections import deque

input = sys.stdin.readline
v = int(input())
e = [[] for _ in range(v + 1)]
for _ in range(v):
    a = list(map(int, input().split()))
    b = 1
    while a[b] != -1:
        e[a[0]].append((a[b], a[b + 1]))
        b += 2

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
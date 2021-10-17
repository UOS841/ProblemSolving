import sys
input = sys.stdin.readline
n = int(input())
connect = [[] for _ in range(n + 1)]
parent = [0 for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    connect[a].append(b)
    connect[b].append(a)

stack = [1]
while stack:
    now = stack.pop()
    for i in connect[now]:
        if parent[i] == 0:
            parent[i] = now
            stack.append(i)
            
for i in range(2, n + 1):
    print(parent[i])
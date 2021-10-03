import sys
input = sys.stdin.readline

def find(x):
    if parent[x] != x:
        return find(parent[x])
    return parent[x]

def union(a, b):
    a, b = find(a), find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n, m, t = map(int, input().split())
graph = []
gragh = [list(map(int, input().split())) for _ in range(m)]
gragh = sorted(gragh, key = lambda x: x[2])
parent = [i for i in range(n + 1)]

ans = 0

for line in gragh:
    a, b, c = line
    if find(a) == find(b):
        continue
    else:
        ans += c
        union(a, b)
print(int(ans + ((n - 1) * (n - 2) * t)/2))
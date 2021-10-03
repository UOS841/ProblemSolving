from collections import deque

n = int(input())
a, b = map(int, input().split())
m = int(input())
route = [[] for _ in range(n)]
visited = [False] * n

for _ in range(m):
    x, y = map(int, input().split())
    route[x - 1].append(y - 1)
    route[y - 1].append(x - 1)

def bfs(start, end):
    count = 0
    q = deque([[start, count]])
    while q:
        value = q.popleft()
        v = value[0]
        count = value[1]
        if v == end:
            return count
        
        if not visited[v]:
            count += 1
            visited[v] = True
            for e in route[v]:
                if not visited[e]:
                    q.append([e, count])
    return -1

print(bfs(a-1, b-1))
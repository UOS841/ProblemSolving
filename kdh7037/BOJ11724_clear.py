from collections import deque

n, m = map(int, input().split())

area = [0 for _ in range(n)]
route = [[0 for _ in range(n)] for _ in range(n)]

def Chk():
    if 0 in area:
        return True
    return False

for i in range(m):
    u, v = map(int, input().split())
    route[u - 1][v - 1], route[v - 1][u - 1] = 1, 1

q = deque()
ans = 0



while Chk():
    q.append(area.index(0))
    area[area.index(0)] = 1
    ans = ans + 1
    while q:
        pas = q.popleft()
        for i in range(n):
            if route[pas][i] == 1 and area[i] == 0:
                q.append(i)
                area[i] = 1
                route[pas][i], route[i][pas] = 0, 0

print(ans)

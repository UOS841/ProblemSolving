from collections import deque

n, m = map(int, input().split())

ch = [list(map(int, input().split())) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def Chk():
    for i in range(1, n+1):
        for j in range(2, m+1):
            if cheese[i][j] == 1:
                return True
    return False

cheese = [[-1 for _ in range(m + 2)] for _ in range(n + 2)]
chk = [[False for _ in range(m + 2)] for _ in range(n + 2)]
q = deque()
ans = 0

for i in range(1, n + 1):
    cheese[i][1 : m + 1] = ch[i - 1]

while Chk():
    chk = [[False for _ in range(m + 2)] for _ in range(n + 2)]
    ans += 1
    q.append([1, 1])

    while q:
         x, y = q.popleft()

         for i in range(4):
             x_ = x + dx[i]
             y_ = y + dy[i]
             
             if (cheese[y_][x_] == 0 or cheese[y_][x_] == 2) and not chk[y_][x_]:
                 cheese[y_][x_] = 2
                 chk[y_][x_] = True
                 q.append([x_, y_])

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if cheese[i][j] == 1:
                cnt = 0

                for k in range(4):
                    if cheese[i + dy[k]][j + dx[k]] == 2:
                        cnt += 1

                if cnt > 1:
                    cheese[i][j] = 0


print(ans)
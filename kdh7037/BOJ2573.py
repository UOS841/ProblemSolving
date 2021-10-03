from collections import deque

n, m = map(int, input().split())
iceberg = [list(map(int, input().split())) for _ in range(n)]
tmp = iceberg
visit = [[0 for _ in range(m)] for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

num = 0

def Chk():
    if iceberg == [[0 for _ in range(m)] for _ in range(n)]:
        num = 0
        return False
    return True

q = deque()
while num > 1:
    for i in range(1, m - 1):
        for j in range(1, n - 1):
            for k in range(4):
                if tmp[i][j] == 0:
                    break
                elif iceberg[i + dx[k]][j + dy[k]] == 0:
                    tmp[i][j] -= 1
    iceberg = tmp

    for i in range(1, m - 1):
        for j in range(1, n - 1):
            if iceberg[i][j] != 0 and visit[i][j] == 0:
                visit[i][j] = 1
                q.append([i, j])
                while q:
                    x, y = q.popleft()
                    for k in range(4):
                        if iceberg[x + dx[k]][y + dy[k]] != 0 and visit[x][y] == 0:
                            visit[x + dx[k]][y + dy[k]] = 1
                            q.append([x + dx[k], y + dy[k]])
                num += 1




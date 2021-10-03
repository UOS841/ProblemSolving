import copy
import sys

m, n = map(int, sys.stdin.readline().split())
box = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visit = [[False] * m for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def Chk():
    for i in range(n):
        for j in range(m):
            if visit[i][j] == False:
                return False
    return True


answer = 0

while True:
    for i in range(n):
        for j in range(m):
            if box[i][j] != 0:
                visit[i][j] = True
    if Chk():
        break
    sign = True
    for i in range(n):
        for j in range(m):
            if box[i][j] != 1 or visit[i][j] == False:
                continue
            for k in range(4):
                x = j + dx[k]
                y = i + dy[k]
                if 0 <= x < m and 0 <= y < n:
                    if visit[y][x] == False and box[y][x] == 0:
                        box[y][x] = 1
                        sign = False
    if sign:
        answer = -1
        break
    answer += 1
print(answer)

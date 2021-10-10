import sys
from collections import deque

dx = [1, 0, -1, 0, 1, 1, -1, -1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

while True:
    w, h = map(int, sys.stdin.readline().split())
    visit = [[False] * w for _ in range(h)]
    if w == 0 and h == 0:
        break
    maps = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    answer = 0
    q = deque()
    for i in range(h):
        for j in range(w):
            if maps[i][j] == 1 and visit[i][j] == False:
                q.append((j, i))
                answer += 1
                visit[i][j] = True
                while q:
                    x_, y_ = q.popleft()
                    for k in range(8):
                        x = x_ + dx[k]
                        y = y_ + dy[k]
                        if 0 <= x < w and 0 <= y < h:
                            if maps[y][x] == 1 and visit[y][x] == False:
                                visit[y][x] = True
                                q.append((x, y))
    print(answer)
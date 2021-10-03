import sys
from collections import deque
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    home = list(map(int, sys.stdin.readline().split()))
    cvs = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        cvs.append([x, y])
    rock = list(map(int, sys.stdin.readline().split()))
    route = [home] + cvs + [rock]
    q = deque()
    visit = [False] * (n + 2)
    q.append(home)
    visit[0] == True
    while q:
        x_, y_ = q.popleft()
        for j in range(n + 2):
            if visit[j] == True:
                continue
            if abs(x_ - route[j][0]) + abs(y_ - route[j][1]) <= 1000:
                q.append(route[j])
                visit[j] = True

    if visit[n + 1] == True:
        print('happy')
    else:
        print('sad')

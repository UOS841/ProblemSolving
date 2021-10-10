import sys
r, c = map(int, sys.stdin.readline().split())

alpha = [list(sys.stdin.readline()) for _ in range(r)]
visit = [[False] * c for _ in range(r)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
ans = 1
stack = [(0, 0, [alpha[0][0]])]
visit[0][0] = True

while stack:
    y_, x_, al = stack[-1]
    for i in range(4):
        x = x_ + dx[i]
        y = y_ + dy[i]
        if 0 <= x < c and 0 <= y < r:
            if alpha[y][x] not in al:
                stack.append((y, x, al.append(alpha[y][x])))
        



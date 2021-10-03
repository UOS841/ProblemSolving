import sys
n, m = map(int, sys.stdin.readline().split())
water = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
shark = []
for i in range(n):
    for j in range(m):
        if water[i][j]:
            shark.append((i, j))

safeDis = 0
for i in range(n):
    for j in range(m):
        preDis = 51
        for x, y in shark:
            dis = max(abs(i - x), abs(j - y))
            preDis = min(preDis, dis)
        safeDis = max(safeDis, preDis)

print(safeDis)
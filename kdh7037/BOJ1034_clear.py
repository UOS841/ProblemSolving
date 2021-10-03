import sys
input = sys.stdin.readline

n, m = map(int, input().split())
lamp = [list(map(int, input().strip())) for _ in range(n)]
k = int(input())

oddeven = k % 2 #0 or 1
ans = 0
for row in lamp:
    if k < row.count(0) or oddeven != row.count(0) % 2:
        continue
    ans = max(ans, lamp.count(row))

print(ans)
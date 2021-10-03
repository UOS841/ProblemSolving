import heapq
import sys

n = int(input())
c = []
q = []

for _ in range(n):
    c.append(list(map(int, sys.stdin.readline().split())))
c = sorted(c, key=lambda x: x[0])

for i in range(n):
    if len(q) != 0 and q[0] <= c[i][0]:
        heapq.heappop(q)
    heapq.heappush(q, c[i][1])

print(len(q))

from collections import deque
import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n, k = map(int, sys.stdin.readline().split())
    d = [0] + list(map(int, sys.stdin.readline().split()))
    start = []
    for i in range(1, k + 1):
        start.append(i)
    order = []
    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        if y in start:
            start.remove(y)
        order.append((x, y))
    w = int(sys.stdin.readline())
    
    dp = [0 for _ in range(n + 1)]
    q = deque()

    for i in range(k):
        if order[i][0] in start:
            q.append(order[i])

    for x, y in order:
        dp[y] = max(dp[y], dp[x] + d[y])
    
    print(dp[w])
    

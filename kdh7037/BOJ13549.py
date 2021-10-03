import sys
from collections import deque
n, k = map(int, sys.stdin.readline().split())
MAX = 100001
q = deque()
sec = [-1] * MAX
check = [False] * MAX
q.append(n)
sec[n] = 0
check[n] = True

while q:
    now = q.popleft()
    if now * 2 < MAX and check[now * 2] == False:
        check[now * 2] = True
        sec[now * 2] = sec[now]
        q.appendleft(now * 2)
    if now + 1 < MAX and check[now + 1] == False:
        check[now + 1] = True
        sec[now + 1] = sec[now] + 1
        q.append(now + 1)
    if now - 1 >= 0 and check[now - 1] == False:
        check[now - 1] = True
        sec[now - 1] = sec[now] + 1
        q.append(now - 1)

print(sec[k])

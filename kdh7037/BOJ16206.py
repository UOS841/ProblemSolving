import sys
n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

a = sorted(sorted(a, key = lambda x : x // 10), key = lambda x : x % 10)

cnt = 0
for i in a:
    if m == 0:
        break
    if i == 10:
        cnt += 1
    elif i % 10 == 0:
        if m 


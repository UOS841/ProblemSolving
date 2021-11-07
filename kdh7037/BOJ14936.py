import sys
n, m = map(int, sys.stdin.readline().split())
ans = 0
case1, case2, case3, case4 = n, n//2, (n+1)//2, (n-1)//3+1

ans += 1

if case1 <= m : ans += 1
if n > 1 and case2 <= m : ans += 1
if n > 1 and case3 <= m : ans += 1
if n > 2 and case4 <= m : ans += 1
if n >= 3 and case2 + case4 <= m : ans += 1
if n >= 3 and case3 + case4 <= m : ans += 1
if n >= 3 and case1 + case4 <= m : ans += 1

print(ans)
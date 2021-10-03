import sys
n = int(sys.stdin.readline())
t, p = [], []
dp = [0] * (n + 1)
for _ in range(n):
    t_, p_ = map(int, sys.stdin.readline().split())
    t.append(t_)
    p.append(p_)

for i in range(n):
    if t[i] <= n - i:
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i])
    dp[i + 1] = max(dp[i + 1], dp[i])

print(dp[n])

'''
dp = 전 날까지 얻을 수 있는 최대 금액
t = 각 날짜 별 얻는 상담이 걸리는 기간
p = 그 날 상담을 진행하면 얻을 수 있는 돈
'''
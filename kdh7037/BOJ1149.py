import sys
n = int(sys.stdin.readline())
house = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [[0] * 3 for _ in range(n)]

for i in range(3):
    dp[0][i] = house[0][i]

for i in range(1, n):
    dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2])
    dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2])
    dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1])

print(min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]))
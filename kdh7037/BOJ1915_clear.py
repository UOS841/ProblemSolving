n, m = map(int, input().split())

arr = [list(input()) for _ in range(n)]

dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

max = 0

for i in range(n):
    for j in range(m):
        if arr[i][j] == '1':
            dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1
            if dp[i + 1][j + 1] > max:
                max = dp[i + 1][j + 1]

print(max * max)
n = int(input())
if n != 1:
    dp = [0] * (n)
    dp[0] = 1
    dp[1] = 2
    for i in range(2, n):
        dp[i] = dp[i - 2] + dp[i - 1]
    print(dp[-1]%10007)
else:
    print(1)
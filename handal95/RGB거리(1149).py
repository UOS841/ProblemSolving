def inputs():
    N = int(input())
    dp = list()

    for r in range(N):
        dp.append(list(map(int, input().split())))

    return (N, dp)


def solve():
    (N, dp) = inputs()

    length = len(dp)
    for i in range(1, length):
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2])
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2])
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1])

    cost = dp[length - 1]
    answer = min(cost[0], min(cost[1], cost[2]))

    print(answer)


solve()

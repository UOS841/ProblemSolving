def solution(m, n, puddles):
    DP = [[0] * m for _ in range(n)]
    for a, b in puddles:
        DP[b - 1][a - 1] = -1
    for i in range(m):
        if DP[0][i] == 0:
            DP[0][i] = 1
        else:
            break
    for i in range(1, n):
        if DP[i][0] == 0:
            DP[i][0] = 1
        else:
            break
    for i in range(1, m):
        for j in range(1, n):
            if DP[j][i] == -1 or (DP[j-1][i] == -1 and DP[j][i-1] == -1):
                continue
            elif DP[j-1][i] == -1:
                DP[j][i] = DP[j][i-1]
            elif DP[j][i-1] == -1:
                DP[j][i] = DP[j-1][i]
            else:
                DP[j][i] = DP[j][i-1] + DP[j-1][i]
    return DP[-1][-1] % 1000000007
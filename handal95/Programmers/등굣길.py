def solution(m, n, puddles):
    dp = [ [0] * (m+2) for row in range(n+2) ]
    dp[1][1] = 1
    
    for row in range(1, n + 1):
        for col in range(1, m + 1):
            if [col, row] in puddles:
                continue
                
            dp[row][col + 1] += dp[row][col] if [col + 1, row] not in puddles else 0
            dp[row + 1][col] += dp[row][col] if [col, row + 1] not in puddles else 0

    answer = dp[n][m] % 1000000007
    return answer
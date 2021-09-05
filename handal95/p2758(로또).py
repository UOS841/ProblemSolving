from sys import stdin


def run(testcase=1):
    for _ in range(int(testcase)):
        solve()


def inputs():
    """
    Input format
    N
    params:
        N   int     1 <= N <= 10
        M   int     1 <= M <= 2000, N <= M
    """
    N, M = map(int, stdin.readline().split())

    return N, M


def solve():
    N, M = inputs()
    
    dp = [[0 for n in range(M + 1)] for m in range(N + 1)]
    
    for col in range(0, M + 1):
        dp[0][col] = 1
    
    for row in range(1, N + 1):
        for col in range(1, M + 1):
            dp[row][col] = dp[row - 1][col // 2] + dp[row][col - 1]
            
    print(dp[row][col])
    
run(input())

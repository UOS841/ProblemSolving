def solution(N, number):
    dp = [ set() for i in range(9) ] 

    answer = -1
    for i in range(1, 9):
        # 초기화 NN
        dp[i].add(int(str(N) * i))
        
        for j in range(i):
            for num1 in dp[j]:
                for num2 in dp[i-j]:
                    dp[i].add(num1 + num2)
                    dp[i].add(num1 - num2)
                    dp[i].add(num1 * num2)
                    if num2 != 0:
                        dp[i].add(num1 // num2)

        # i 번 사용중에 answer가 있다면, Return
        if number in dp[i]:
            answer = i
            return answer

    return -1
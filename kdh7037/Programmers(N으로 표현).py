def solution(N, number):
    answer = 0
    DP = [0]
    for i in range(1, 9):
        numset = set()
        numset.add(int(str(N) * i))
        
        for j in range(1, i):
            for x in DP[j]:
                for y in DP[i - j]:
                    numset.add(x + y)
                    numset.add(x - y)
                    numset.add(x * y)
                    if y != 0:
                        numset.add(x // y)
        if number in numset:
            return i
        DP.append(numset)
    return -1
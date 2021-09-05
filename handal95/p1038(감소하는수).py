import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    N
    params:
        N   int     0 <  N <= 10 e6
    """
    N = int(stdin.readline())

    return N


def solve():
    N = inputs()

    if N == 0 :
        print(0)
        return
    elif N >= 1023:
        print(-1)
        return
    
    cnt = 0
    answer = 1
    while True:
        str_num = str(answer)
        length = len(str_num)
        flag = True
        if length > 1:
            for i in range(1, length):
                if int(str_num[i]) >= int(str_num[i - 1]):
                    start = str_num[: i - 1]
                    mid = str(int(str_num[i - 1]) + 1)
                    end = "0" + str_num[i + 1 :]
                    answer = int(start + mid + end)
                    flag = False
                    break

        if flag:
            cnt += 1

            if cnt == N:
                print(answer)
                return
            answer += 1


run()

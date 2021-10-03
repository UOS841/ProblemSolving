def solution(s):
    length = len(s)
    min = 1000
    if length == 1:
        min = 1
    else:
        for i in range(1, int(length/2) + 1):
            stri = 0
            overlap = 1
            tmp1, tmp2 = [], []
            for j in range(0, length, i):
                tmp2 = s[j : j + i]
                if len(tmp2) != i:
                    stri = stri + len(tmp2)
                elif tmp1 != tmp2:
                    tmp1 = tmp2
                    stri = stri + i
                    if overlap != 1:
                        stri = stri + len(str(overlap))
                    overlap = 1
                elif tmp1 == tmp2:
                    overlap = overlap + 1
            if overlap != 1:
                stri = stri + len(str(overlap))
            if min > stri:
                min = stri
    return min
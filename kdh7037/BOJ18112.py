import sys

startBin = list(map(int, sys.stdin.readline().strip()))
endBin = list(map(int, sys.stdin.readline().strip()))

"""
01  100  100
11  011  010

1    100   100
11    11    10

01   100    100    10100
11   011    010    01011


"""

startLen, endLen = len(startBin), len(endBin)
if startLen == endLen:
    while startBin[0] == endBin[0]:
        del startBin[0]
        del endBin[0]
    while startBin[-1] == endBin[-1]:
        del startBin[-1]
        del endBin[-1]
    if len(startBin) != 0:
        while startBin[0] == 0:
            del startBin[0]
            if len(startBin) == 0:
                break
    if len(endBin) != 0:
        while endBin[0] == 0:
            del endBin[0]
            if len(endBin) == 0:
                break
    startLen, endLen = len(startBin), len(endBin)


answer = 0
if startLen > endLen:
    answer += startBin.count(1)
    startLen -= 1
    while startLen != endLen:
        answer += startLen
        startLen -= 1
    answer += endBin.count(0)
elif startLen < endLen:
    answer += startBin.count(0) + 1
    startLen += 1
    while startLen != endLen:
        answer += startLen
        startLen += 1
    answer += endBin.count(1) - 1
print(answer)

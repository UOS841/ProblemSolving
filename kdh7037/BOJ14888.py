n = int(input())
numbers = list(map(int, input().split()))
symbol = list(map(int, input().split()))

maxNum = -1000000001
minNum = 1000000001
num = 0

def cal(num, idx, add, sub, mul, div):
    if idx == n:
        global maxNum, minNum
        maxNum = max(num, maxNum)
        minNum = min(num, minNum)
        return
    else:
        if add:
            cal(num + numbers[idx], idx + 1, add - 1, sub, mul, div)
        if sub:
            cal(num - numbers[idx], idx + 1, add, sub - 1, mul, div)
        if mul:
            cal(num * numbers[idx], idx + 1, add, sub, mul - 1, div)
        if div:
            if num < 0:
                cal(-((- num) // numbers[idx]), idx + 1, add, sub, mul, div - 1)
            else:
                cal(num // numbers[idx], idx + 1, add, sub, mul, div - 1)

cal(numbers[0], 1, symbol[0], symbol[1], symbol[2], symbol[3])
print(maxNum)
print(minNum)
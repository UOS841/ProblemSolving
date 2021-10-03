import sys

def ans(arr, idx, equ1, equ2):
    if idx == (len(arr) - 1):
        equ1 += str(arr[idx])
        equ2 += str(arr[idx])
        result = int(eval(equ1))
        if result == 0:
            answer.append(equ2)
    else:
        ans(arr, idx + 1, equ1 + str(arr[idx]), equ2 + str(arr[idx]) + " ")
        ans(arr, idx + 1, equ1 + str(arr[idx]) + "+", equ2 + str(arr[idx]) + "+")
        ans(arr, idx + 1, equ1 + str(arr[idx]) + "-", equ2 + str(arr[idx]) + "-")

t = int(sys.stdin.readline())
answer = []

for _ in range(t):
    n = int(sys.stdin.readline())
    numArr = list(range(1, n + 1))
    ans(numArr, 0, "", "")
    for i in answer:
        print(i)
    print()
    answer = []
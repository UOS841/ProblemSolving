import sys
n = int(input())
a = list(map(int, sys.stdin.readline().split()))
nge = [-1] * n
stack = [0]

for i in range(len(a)):
    while stack and a[stack[-1]] < a[i]:
        nge[stack.pop()] = a[i]
    stack.append(i)

for i in range(n):
    print(nge[i], end = ' ')
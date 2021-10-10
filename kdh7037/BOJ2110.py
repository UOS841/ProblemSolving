import sys
input = sys.stdin.readline
n, c = map(int, input().split())
x = [int(input()) for _ in range(n)]
x.sort()
left, right = 1, x[-1] - x[0]
while left <= right:
    mid = (left + right) // 2

    count = 1
    current_x = x[0]
    for i in range(1, n):
        if current_x + mid <= x[i]:
            count += 1
            current_x = x[i]

    if count >= c:
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer)
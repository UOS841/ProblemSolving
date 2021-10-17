import sys
input = sys.stdin.readline
n = int(input())
k = int(input())

left, right = 1, k
while left <= right:
    mid = (left + right) // 2

    small = 0

    for i in range(1, n + 1):
        small += min(mid//i , n) #몫 or 최댓값
    
    if small >= k:
        right = mid - 1
    else:
        left = mid + 1
print(left)
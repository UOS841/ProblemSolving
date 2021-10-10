import sys
input = sys.stdin.readline
k, n = map(int, input().split())
lan = [int(input()) for _ in range(k)]

left, right = 1, max(lan)
ans = 0
while left <= right:
    mid = (left + right) // 2
    
    num = 0
    for i in lan:
        num += (i // mid)
    
    if num >= n:
        ans = mid
        left = mid + 1
    else:
        right = mid - 1
print(ans)
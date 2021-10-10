import sys
input = sys.stdin.readline
n, m = map(int, input().split())
tree = list(map(int, input().split()))

left, right = 1, max(tree)
ans = 0
while left <= right:
    mid = (left + right) // 2
    
    num = 0
    for i in tree:
        if i - mid > 0: num += i - mid
    
    if num >= m:
        ans = mid
        left = mid + 1
    else:
        right = mid - 1
print(ans)
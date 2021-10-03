n = int(input())
arr = list(map(int, input().split()))

max = -1001
tmp = -1001
for i in range(n):
    if arr[i] >= arr[i] + tmp:
        tmp = arr[i]
    else:
        tmp = arr[i] + tmp
    
    if max < tmp:
        max = tmp

print(max)
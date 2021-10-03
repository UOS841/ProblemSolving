import sys
#num = 삭제할거, #arr = Tree
def dfs(num, arr):
    arr[num] = -2
    for i in range(len(arr)):
        if num == arr[i]:
            dfs(i, arr)

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
k = int(sys.stdin.readline())
count = 0

dfs(k, arr)
count = 0
for i in range(len(arr)):
    if arr[i] != -2 and i not in arr:
        count += 1
print(count)
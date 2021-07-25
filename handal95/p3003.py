stones = list(map(int, input().split()))
default = [1, 1, 2, 2, 2, 8]

for i in range(len(default)):
    print(default[i] - stones[i], end=" ")

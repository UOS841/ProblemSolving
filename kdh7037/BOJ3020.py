import sys
n, h = map(int, sys.stdin.readline().split())
bottom = [0] * (h + 1)
top = [0] * (h + 1)
for i in range(n):
    obstacle = int(sys.stdin.readline())
    if i % 2:
        top[obstacle] += 1
    else:
        bottom[obstacle] += 1

for i in range(h - 1, 0, -1):
    top[i - 1] += top[i]
    bottom[i - 1] += bottom[i]

breaking = [0] * (h + 1)
for i in range(1, h + 1):
    breaking[i] = bottom[i] + top[h - i + 1]

minNum = min(breaking[1:])
print(minNum)
print(breaking[1:].count(minNum))
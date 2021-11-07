import sys
from itertools import combinations

N = int(sys.stdin.readline())
arr = []

for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split(" "))))

combi = []
for i in range(1, N+1):
    combi.append(combinations(arr, i))

answer = 1000000000
for i in combi:
    for j in i:
        sour = 1
        bitter = 0
        for k in j:
            sour *= k[0]
            bitter += k[1]

        answer = min(answer, abs(sour - bitter))

print(answer)
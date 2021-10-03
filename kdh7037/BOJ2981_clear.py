import math

n = int(input())
game = list(int(input()) for _ in range(n))
game.sort()
sub = list()
#sub은 차이

for i in range(1, n):
    sub.append(game[i] - game[i - 1])

subgcd = sub[0]
for i in range(1, len(sub)):
    subgcd = math.gcd(subgcd, sub[i])

ans = list()

#약수
for i in range(2, int(math.sqrt(subgcd)) + 1):
    if subgcd % i == 0:
        ans.append(i)
        ans.append(subgcd//i)
ans.append(subgcd)
ans = list(set(ans))
ans.sort()
for i in ans:
    print(i, end = ' ')
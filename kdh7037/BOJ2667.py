from collections import deque

n = int(input())

house = [[-1 for _ in range(n + 2)] for _ in range(n + 2)]
check = [[False for _ in range(n + 2)] for _ in range(n + 2)]

for i in range(1, n + 1):
    house[i][1:n+1] = list(map(int, input()))

def Chk():
    for i in range(1, n+1):
        for j in range(1, n+1):
            if house[i][j] == 1:
                return True
    return False

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

q = deque()
ans = 0

while Chk():
    ans = ans + 1
    
print(house)
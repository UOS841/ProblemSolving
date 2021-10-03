n = int(input())

baseball = []

for i in range(n):
    baseball.append(list(map(int, input().split())))
    baseball[i][0] = str(baseball[i][0])

ans = 0

for i in range(111, 1000):
    i = str(i)
    if '0' in i:
        continue
    if i[0] == i[1] or i[0] == i[2] or i[1] == i[2]:
        continue
    chk = True
    for game in baseball:
        s, b = 0, 0
        for j in range(3):
            if game[0][j] == i[j]:
                s = s + 1
            elif game[0][j] in i:
                b = b + 1

        if game[1] != s or game[2] != b:
            chk = False
            break
    if chk == True:
        ans = ans + 1

print(ans)
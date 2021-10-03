n = int(input())

room = [list(input()) for _ in range(n)]

w, l = 0, 0

for i in range(0, n):
    check = False
    for j in range(1, n):
        if room[i][j - 1] == '.' and room[i][j] == '.' and check == False:
            w = w + 1
            check = True
        if room[i][j - 1] == 'X' or room[i][j] == 'X':
            check = False

for i in range(0, n):
    check = False
    for j in range(1, n):
        if room[j - 1][i] == '.' and room[j][i] == '.' and check == False:
            l = l + 1
            check = True
        if room[j - 1][i] == 'X' or room[j][i] == 'X':
            check = False

print("{} {}".format(w, l))
            
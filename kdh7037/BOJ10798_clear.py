board = [[-1] * 15 for _ in range(5)]
for i in range(5):
    sentence = list(input())
    for j in range(len(sentence)):
        board[i][j] = sentence[j]

for i in range(15):
    for j in range(5):
        if board[j][i] == -1:
            continue
        else:
            print(board[j][i], end = '')
    
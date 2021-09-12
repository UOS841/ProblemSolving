ATTACK = 1
HEAL = 2

def solution(board, skills):
    
    DIVIDE = 10
    
    
    STEP = len(board) // DIVIDE
    
    new_boards = list([] for _ in range(STEP + 1))

    for r in range(0, DIVIDE):
        print(r)
        new_boards[r].append(board[r * STEP : (r + 1) * STEP])
        
        
    return
    skills = sorted(skills, reverse=True)
    
    print(skills)
    
    for skill in skills:
        type_, r1, c1, r2, c2, degree = skill
        
        for r in range(r1, r2 + 1):
            for c in range(c1, c2 + 1):
                if type_ == ATTACK:
                    board[r][c] -= degree
                elif type_ == HEAL:
                    board[r][c] += degree
        
    answer = 0
    for r in range(len(board)):
        for c in range(len(board[0])):
            if board[r][c] > 0:
                answer += 1       
    
    return answer

print(solution(
    [
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
        [5, 5, 5, 5, 5, 5, 5, 5, 5, 5]
    ],
    [
        [1, 0, 0, 3, 4, 4], 
        [1, 2, 0, 2, 3, 2], 
        [1, 0, 1, 3, 3, 1],
        [2, 1, 0, 3, 1, 2], 
    ]
))
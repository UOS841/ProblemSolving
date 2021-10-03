def count_score(ryan, appeach):
    score = 0

    for i in range(11):
        if ryan[i] > appeach[i]:
            score += i
        else:
            score -= i
            
    return score
    

def backtrack(ryan, appeach, i, left_arrow, cur_score):
    if i == 10 or left_arrow <= 0:
        if left_arrow > 0:
            ryan[-1] = left_arrow
        scores = count_score(ryan, appeach)
        return scores, ryan
    
    # 쏘고 넘기기
    if left_arrow > appeach[i]:
        shoot_score = cur_score + i
        shoot_arrow = left_arrow - appeach[i] - 1
        shoot_ryan = ryan.copy()
        shoot_ryan[i] = appeach[i] + 1
    
        next_score, next_ryan = backtrack(
            shoot_ryan, appeach, i + 1, shoot_arrow, shoot_score)
        
    # 쏘지 않고 넘기기
    unshoot_score = cur_score
    unshoot_arrow = left_arrow
    unshoot_ryan = ryan.copy()
    
    skip_score, skip_ryan = backtrack(
        unshoot_ryan, appeach, i + 1, unshoot_arrow, unshoot_score)
# 2 ^ 11 < 
    if left_arrow > appeach[i]:  
        if next_score > skip_score:
            if cur_score > next_score:
                return cur_score, ryan
            else:
                return next_score, next_ryan

    if cur_score > skip_score:
        return cur_score, ryan
    else:
        return skip_score, skip_ryan
        
def solution(n, info):
    ryan = [0] * 11
    appeach = info[::-1]
    
    score, ryan = backtrack(ryan, appeach, 0, n, 0)
    
    print("=====")
    print(score)
    print("R:", ryan)
    print("A:", appeach)
    answer = ryan
    if score <= 0:
        return [-1]
    
    return answer


print(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]))
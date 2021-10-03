def solution(s):
    answer = len(s)

    for n in range(1, len(s)):
        new_str = ''
        
        count = 1
        for p in range(0, len(s), n):
            cur_str = s[p     : p + n]
            nxt_str = s[p + n : p + 2 * n]
            
            if cur_str == nxt_str:
                count += 1
            else:
                count = count if count > 1 else ''
                new_str += f"{count}{cur_str}"
                count = 1

        # 마지막 문자열
        count = count if count > 1 else ''
        new_str += f"{count}{nxt_str}"
        answer = min(answer, len(new_str))
    
    return answer
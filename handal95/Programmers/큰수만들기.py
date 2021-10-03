def solution(number, k):
    stack = []

    for idx, char in enumerate(number):
        while len(stack) > 0 and stack[-1] < char and k > 0:
            stack.pop()
            k -= 1
        
        if k == 0:
            stack.extend([x for x in number[idx:]])
            break

        stack.append(char)
    
    stack = stack if k == 0 else stack[:-k]
           
    answer = ''.join(stack)
    return answer
def solution(number, k):
    i = 0
    number = list(number)
    while k > 0:
        if i == len(number) - 1:
            for j in range(k):
                del number[-1]
            break
        if int(number[i]) < int(number[i + 1]):
            del number[i]
            k -= 1
            if i != 0: 
                i -= 1
        else:
            i += 1
    return ''.join(number)
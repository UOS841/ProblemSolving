def solution(n, times):
    left = 1
    right = n * max(times)
    while left < right:
        mid = (left + right) // 2
        
        judge = 0
        for time in times:
            judge += mid // time
            
        if judge >= n:
            right = mid
        else:
            left = mid + 1
    answer = left
    return answer
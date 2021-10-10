from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N, C = map(int, stdin.readline().split())
    
    houses = list()
    for i in range(N):
        houses.append(int(stdin.readline()))

    return N, C, houses

def solve():
    N, C, houses = inputs()
    houses.sort()
    
    def binary_search(left, right):
        answer = 0
        while left <= right:
            mid = (left + right) // 2
            pivot = houses[0]
            count = 1
            
            for i in range(1, N):
                if houses[i] >= pivot + mid:
                    count += 1
                    pivot = houses[i]
            
            if count >= C:
                left = mid + 1
                answer = mid
            else:
                right = mid - 1

        return answer

    min_distance = 1
    max_distance = houses[-1] - houses[0]
    answer = binary_search(min_distance, max_distance)
    
    print(answer)

run()

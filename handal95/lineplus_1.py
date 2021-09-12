def solution(student, k):
    answer = -1

    juniors = [-1]
    for i, s in enumerate(student):
        if s == 1:
            juniors.append(i)
    juniors.append(len(student))

    answer = 0

    for i, j in enumerate(juniors[: -1 - k]):
        front = juniors[i + 1] - juniors[i]
        behind = juniors[i + k + 1] - juniors[i + k]

        answer += front * behind

    return answer


print(solution([1, 1], 1))

def solution(jobs):
    answer = []

    queue = []
    for (request_time, process_time, index, priority) in jobs:
        queue.append((request_time, process_time, index, priority))

        print(request_time, process_time, index, priority)

    answer = [1, 1, 2, 1, 2, 2, 3, 3, 1, 1, 1]

    # 중복 제거
    answers = [-1]
    for work in answer:
        if work != answers[-1]:
            answers.append(work)

    return answers[1:]


print(
    solution(
        [
            [1, 5, 2, 3],
            [2, 2, 3, 2],
            [3, 1, 3, 3],
            [5, 2, 1, 5],
            [7, 1, 1, 1],
            [9, 1, 1, 1],
            [10, 2, 2, 9],
        ]
    )
)

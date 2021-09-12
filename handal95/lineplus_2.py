def solution(research, n, k):

    alphabets = "abcdefghijklmnopqrstuvwxyz"
    searched = list([] for _ in range(len(research)))
    issued = list(0 for _ in range(len(alphabets)))

    for i, daily_search in enumerate(research):
        for alphabet in alphabets:
            count = daily_search.count(alphabet)
            searched[i].append(0)
            if count >= k:
                searched[i][ord(alphabet) - ord("a")] = count

    for i, daily_search in enumerate(research):
        if i + 1 < n:
            continue

        for alphabet in alphabets:
            if searched[i][ord(alphabet) - ord("a")] >= k:
                count = 0
                flag = True
                for j in range(n):
                    count += searched[i - j][ord(alphabet) - ord("a")]
                    if searched[i - j][ord(alphabet) - ord("a")] < k:
                        flag = False
                        break

                if flag is True and count >= 2 * n * k:
                    issued[ord(alphabet) - ord("a")] += 1
                    print(f"alphabets : {alphabet}")

    answer = "None"
    maximum = 0
    for i, count in enumerate(issued):
        if count > maximum:
            answer = chr(ord("a") + i)
            maximum = count

    return answer


print(solution(["abaaaa", "aaa", "abaaaaaa", "fzfffffffa"], 2, 2))

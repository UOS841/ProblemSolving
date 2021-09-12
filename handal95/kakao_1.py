def solution(id_list, reports, k):
    answer = [0 for n in range(len(id_list))]

    reports = list(set(reports))

    blacklist = dict()
    for id in id_list:
        blacklist[id] = list()

    for report in reports:
        user, block = report.split(" ")
        blacklist[block].append(user)

    for id in blacklist:
        if len(blacklist[id]) >= k:
            for report_user in blacklist[id]:
                report_id = id_list.index(report_user)
                answer[report_id] += 1

    return answer


print(
    solution(
        ["muzi", "frodo", "apeach", "neo"],
        ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"],
        2,
    )
)

# test 1
# ["muzi", "frodo", "apeach", "neo"],
# ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"],
# 2

# test 2
# ["con", "ryan"],
# ["ryan con", "ryan con", "ryan con", "ryan con"],
# 3

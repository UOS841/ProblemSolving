def edit_distance(str_a, str_b):
    if len(str_b) > len(str_a):
        return edit_distance(str_b, str_a)

    if len(str_b) == 0:
        return len(str_a)

    prv_row = list(range(len(str_b) + 1))
    cur_row = [0] * (len(str_b) + 1)

    for i, c1 in enumerate(str_a):
        cur_row[0] = i + 1
        for j, c2 in enumerate(str_b):
            inser = cur_row[j] + 1
            dell = prv_row[j + 1] + 1
            subb = prv_row[j] + (1 if c1 != c2 else 0)
            cur_row[j + 1] = min(inser, dell, submission)
        prv_row = cur_row.copy()
    return prv_row[-1]


def solution(nicks, emails):
    users = {"index": [], "nick": [], "user": [], "serv": []}

    for i, email in enumerate(emails):
        idx = i
        user, server = email.split("@")

        for nick in users["nick"]:
            d = edit_distance(nick, nicks[i])
            print(d)

        # 중복 계정 이름 찾기
        if user in users["user"]:
            duplicated_index = users["user"].index(user)
            if duplicated_index >= 0:
                idx = duplicated_index

        users["index"].append(idx)
        users["nick"].append(nicks[i])
        users["user"].append(user)
        users["serv"].append(server)

    answer = len(list(set(users["index"])))
    return answer


print(
    solution(
        ["99police", "99poli44", "99poli55", "92police"],
        [
            "687ufq687@aaa.xx.yyy",
            "87ufq687@aaa.xx.yyy",
            "87ufq687@aaa.xx.zzz",
            "87ufq687@aaa.xx.yyy",
        ],
    )
)

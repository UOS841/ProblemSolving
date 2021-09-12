from itertools import combinations


def solution(orders, course):

    temp = dict()

    for num in course:
        temp[num] = []

    for order in orders:
        for num in course:
            if num > len(order):
                break
            else:
                temp[num] += list(combinations(sorted(list(order)), num))

    result = []
    for menus in temp.values():
        max_num = 2
        for menu in menus:
            cnt = menus.count(menu)
            if cnt > max_num:
                max_num = cnt

        for menu in menus:
            m = "".join(menu)
            if max_num == menus.count(menu) and m not in result:
                result.append(m)

    return sorted(result)

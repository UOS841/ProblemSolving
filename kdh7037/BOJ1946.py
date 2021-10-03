t = int(input())
for _ in range(t):
    n = int(input())
    volunteer = []
    for _ in range(n):
        grade = list(map(int, input().split()))
        if volunteer == []:
            volunteer.append(grade)
            continue
        tmp = volunteer
        for i in tmp:
            j = i
            if i[0] < grade[0] and i[1] < grade[1]:
                break
            elif i[0] > grade[0] and i[1] > grade[1]:
                volunteer.remove(i)
            if j == tmp[-1]:
                volunteer.append(grade)
                print(volunteer)
                break
    print(len(volunteer))
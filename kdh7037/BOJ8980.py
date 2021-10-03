from operator import itemgetter

n, c = map(int, input().split())
m = int(input())
send = []
for i in range(m):
    send.append(list(map(int, input().split())))

send.sort(key = itemgetter(1, 0))

spare = [c for _ in range(n - 1)]

completion = 0

for i in range(m):
    mi = min(spare[send[i][0] - 1 : send[i][1] - 1])
    if send[i][2] > mi:
        spare[send[i][0] - 1 : send[i][1] - 1] = [spare[j] - mi for j in range(send[i][0] - 1, send[i][1] - 1)]
        completion += mi
    else:
        spare[send[i][0] - 1 : send[i][1] - 1] = [spare[j] - send[i][2] for j in range(send[i][0] - 1, send[i][1] - 1)]
        completion += send[i][2]
print(completion)


n, m = map(int, input().split())
chart = []
for _ in range(n):
    chart.append(list(map(int, input().split())))

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    ssum = 0
    for j in range(y1 - 1, y2):
        ssum += sum(chart[j][x1 - 1 : x2])
    print(ssum)
L, P = map(int, input().split())
expected = input().split()

participants = L * P
for i in range(5):
    print(int(expected[i]) - participants, end=' ')

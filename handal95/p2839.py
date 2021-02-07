N = int(input())

bag3 = 0
bag5 = -1

for i in range(5):
    if N % 5 == 0:
        bag5 = N // 5
        break
    N -= 3
    bag3 += 1

if bag5 == -1:
    print(-1)
else:
    print(int(bag3+bag5))

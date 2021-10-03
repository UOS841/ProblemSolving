sequence = input()

num = len(sequence)

check = [0 for _ in range(num)]

if num > 9:
    num = (num - 9)/2 + 9

for i in range(num, 0, -1):
    inx = sequence.find(str(num))
    if 
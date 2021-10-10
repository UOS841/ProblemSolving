tmpequ = list(input())

tmpstr = ''
equation = []
for i in range(len(tmpequ)):
    if tmpequ[i] == '+' or tmpequ[i] == '-':
        equation.append(tmpequ[i])
    else:
        tmpstr += tmpequ[i]
        if i == len(tmpequ) - 1 or tmpequ[i + 1] == '+' or tmpequ[i + 1] == '-':
            equation.append(int(tmpstr))
            tmpstr = ''

if '-' in equation:
    idx = equation.index('-')
    front = equation[:idx:2]
    rear = equation[idx+1::2]
    print(sum(front) - sum(rear))
else:
    sumequation = equation[::2]
    print(sum(sumequation))


origin = input()
boom = input()

s = []
for i in origin:
    comp = True

    s.append(i)

    if len(s) >= len(boom):
        comp = True
        for j in range(-1,-len(boom)-1,-1):
            if s[j] != boom[j]:
                comp = False
                break
        
        if comp == True:
            a = 0
            while a < len(boom):
                s.pop()
                a += 1


if len(s) == 0:
    print('FRULA')
else:
    str=""
    for i in s:
        str += i
    print(str)
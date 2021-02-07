Xpos = list()
Ypos = list()

for _ in range(3):
    x, y = input().split()
    Xpos.append(x) if x not in Xpos else Xpos.remove(x)
    Ypos.append(y) if y not in Ypos else Ypos.remove(y)

print(*Xpos, *Ypos)

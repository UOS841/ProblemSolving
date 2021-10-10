import sys
input = sys.stdin.readline

s = list(map(str, input().strip()))
t = list(map(str, input().strip()))

while len(s) != len(t):
    if t[-1] == 'A':
        t.pop()
    else:
        t.pop()
        t = t[::-1]

if s == t:
    print(1)
else:
    print(0)

'''
B -> BA ->, BB->
ABBA

ABBA <- ABB <- BA <- B O
B

ABB <- BA X
AB
'''
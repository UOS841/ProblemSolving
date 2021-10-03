import sys

#ipv6 문자열
ipv6 = sys.stdin.readline()
index = ipv6.find('::')
if index != -1:
    co = ipv6.count(':')
    for i in range(7 - co):
        ipv6 = ipv6[:index] + ':' + ipv6[index:]
#1::54ds
#1:::::::54ds
sp = ipv6[:-1].split(':')
#['1','','','','','','54ds'] \n

for i in range(len(sp)):
    zeroNum = 4 - len(sp[i])
    for j in range(zeroNum):
        sp[i] = '0' + sp[i]

'''
::1
1::
리스트 9개 됨
'''

if len(sp) == 9:
    if sp[0] == '0000':
        sp = sp[1:]
    else:
        sp = sp[:-1]
        
print(":".join(sp))
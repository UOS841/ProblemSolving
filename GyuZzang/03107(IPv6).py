ipv6 = input()

while ipv6.count(':') < 7 :
    ipv6 = ipv6.replace('::',':::',1)
while ipv6.count(':') > 7 :
    ipv6 = ipv6.replace('::',':')
    
group = ''
for i in ipv6:
    if i == ':' :
        while(len(group) < 4):
            group = '0' + group
        group += ':'
        print(group,end='')
        group=''
    else :
        group += i

while(len(group) < 4):
    group = '0' + group
    
print(group)
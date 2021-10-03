import sys
dic = {}
sum = 0
while True:
    a = sys.stdin.readline().rstrip()
    if not a:
        break
    if a in dic.keys():
        dic[a] += 1
    else:
        dic[a] = 1
    sum += 1
kdic = sorted(dic)
for i in kdic:
    print('%s %.4f' %(i, dic[i]/sum*100))
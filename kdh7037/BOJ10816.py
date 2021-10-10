import sys
from collections import Counter
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

num = Counter(a)

for i in b:
    print(num[i])
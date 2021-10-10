'''
import sys
n = int(sys.stdin.readline())
card = [int(sys.stdin.readline()) for _ in range(n)]
s = 0
while len(card) != 1:
    card.sort()
    for i in range(0, int(len(card)/2)):
        card[i] += card[i + 1]
        s += card[i]
        del card[i + 1]

print(s)
1 1 100 100
1 1 1 100
'''

import heapq
import sys
n = int(sys.stdin.readline())
card = []
for _ in range(n):
    heapq.heappush(card, int(sys.stdin.readline()))
s = 0
while len(card) != 1:
    a = heapq.heappop(card)
    b = heapq.heappop(card)
    ab = a + b
    s += ab
    heapq.heappush(card, ab)
print(s)

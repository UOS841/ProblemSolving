h, w = map(int, input().split())
blocks = list(map(int, input().split()))

maxBlock = max(blocks)
maxIndex = blocks.index(maxBlock)

stand = -1
waterLeft = 0
for i in range(maxIndex):
    if stand < blocks[i]:
        stand = blocks[i]
    else:
        waterLeft += (stand - blocks[i])

stand = -1
waterRight = 0
for i in range(len(blocks) - 1, maxIndex, -1):
    if stand < blocks[i]:
        stand = blocks[i]
    else:
        waterRight += (stand - blocks[i])

print(waterLeft + waterRight)
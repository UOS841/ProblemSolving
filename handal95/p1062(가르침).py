import re
import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N, K = map(int, stdin.readline().split())

    words = list()
    for _ in range(N):
        word = re.sub("[antic]", "", str(stdin.readline().split()))
        words.append(list(set(list(word[2:-2]))))

    return K, words


def solve():
    K, words = inputs()

    if K < 5:
        print(0)
        return

    def word2bin(word):
        bin = 0b0
        for c in word:
            bin = bin | (1 << (ord(c) - ord("a")))

        return bin

    chars = [chr(x) for x in range(ord("a"), ord("z") + 1)]
    combine = list(map("".join, itertools.combinations(chars, K - 5)))

    for i, word in enumerate(words):
        words[i] = word2bin(word)

    answer = 0
    for pattern in combine:
        bpattern = word2bin(pattern)

        result = 0
        for word in words:
            if bpattern == bpattern | word:
                result += 1
        answer = max(answer, result)

    print(answer)


run()

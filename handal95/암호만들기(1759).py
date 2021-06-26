def inputs():
    L, C = map(int, input().split())
    chars = list(map(str, input().split()))

    return L, C, chars


def solve():
    VOWEL = ["a", "e", "i", "o", "u"]
    L, C, chars = inputs()

    chars.sort()
    answers = list()
    words = list()

    def dfs(depth, idx):
        if depth == L:
            num_vowel = 0

            for c in words:
                if c in VOWEL:
                    num_vowel += 1

            if num_vowel >= 1 and (L - num_vowel) >= 2:
                answers.append("".join(words))

            return

        for i in range(idx, C):
            words.append(chars[i])
            dfs(depth + 1, i + 1)
            words.pop()

    dfs(0, 0)

    answers.sort()
    for answer in answers:
        print(answer)


solve()

from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N = int(stdin.readline())
    cards = map(int, stdin.readline().split())

    M = int(stdin.readline())
    targets = map(int, stdin.readline().split())

    return N, cards, M, targets


def solve():
    N, cards, M, targets = inputs()
    
    cards = sorted(cards)

    card_key = dict()
    for card in cards:
        if card not in card_key.keys():
            card_key[card] = 1
        else:
            card_key[card] += 1

    answer = ""
    for target in targets:
        if target not in card_key.keys():
            card_key[target] = 0
            
        answer += f"{card_key[target]} "

    print(answer)

run()

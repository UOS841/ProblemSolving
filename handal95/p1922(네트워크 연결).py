from sys import stdin
from queue import PriorityQueue


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    N
    M
    ( a b c )* M

    params:
        N     # of Computer (1 <= N <= 1,000)
        M     # of link     (1 <= M <= 100,000)
        a, b  index of computer
        c     cost of linking

    """

    N = int(stdin.readline())
    M = int(stdin.readline())

    links = list()
    for m in range(M):
        links.append(list(map(int, stdin.readline().split())))

    return N, links


def solve():
    N, links = inputs()

    pq = PriorityQueue()
    for link in links:
        if link[0] == link[1]:
            continue

        (A, B) = (link[0], link[1]) if link[0] < link[1] else (link[1], link[0])
        pq.put((link[2], (A - 1, B - 1)))

    parent = [x for x in range(0, N)]

    answer = 0
    while not pq.empty():
        cost, (A, B) = pq.get()

        if parent[A] == parent[B]:
            continue

        answer += cost
        parent = [parent[A] if x == parent[B] else x for x in parent]

    print(answer)


run()

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
        N     # of city         (1 <= N <= 10,000)
        M     # of road         (1 <= M <= 30,000)
        T     increasing value of cost     (1 <= T <= 10)
        a, b  index of city
        c     cost of linking

    """

    N, M, T = map(int, stdin.readline().split())

    links = list()
    for m in range(M):
        links.append(list(map(int, stdin.readline().split())))

    return N, T, links


def solve():
    N, T, links = inputs()

    pq = PriorityQueue()
    for link in links:
        if link[0] == link[1]:
            continue

        (A, B) = (link[0], link[1]) if link[0] < link[1] else (link[1], link[0])
        pq.put((link[2], (A - 1, B - 1)))

    parent = [x for x in range(0, N)]

    count = 0
    answer = 0
    while not pq.empty():
        cost, (A, B) = pq.get()

        if parent[A] == parent[B]:
            continue

        answer += cost + ( count * T )
        count += 1
        parent = [parent[A] if x == parent[B] else x for x in parent]

    print(answer)


run()

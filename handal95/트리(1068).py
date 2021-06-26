def inputs():
    N = int(input())
    parents = list(map(int, input().split()))
    D = int(input())

    return N, parents, D


def solve():
    N, parents, D = inputs()

    # Init nodes
    root = None
    nodes = [{"delete": False, "children": list()} for _ in range(N)]
    for i in range(N):
        if parents[i] == -1:
            root = i
            continue

        nodes[parents[i]]["children"].append(i)

    # Delete the target node
    nodes[D]["delete"] = True

    answer = 0
    # BFS undelete nodes
    queue = [root] if root != D else []
    while len(queue) > 0:
        node = queue.pop(0)

        leaf_node = True
        for c in nodes[node]["children"]:
            if not nodes[c]["delete"]:
                queue.append(c)
                leaf_node = False

        if leaf_node:
            answer += 1

    print(answer)


solve()

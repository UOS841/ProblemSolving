from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N = int(stdin.readline())

    tree = dict()
    for _ in range(N):
        node, left, right = stdin.readline()[:-1].split(' ')
        tree[node] = [left, right]

    return N, tree


def solve():
    N, tree = inputs()

    def ordering(mode, node='A'):
        if node == '.':
            return

        if mode == "preorder":
            print(node, end='')

        ordering(tree[node][0])

        if mode == "inorder":
            print(node, end='')

        ordering(tree[node][1])

        if mode == "postorder":
            print(node, end='')

    
    ordering('preorder')
    print()
    ordering('inorder')
    print()
    ordering('postorder')

run()


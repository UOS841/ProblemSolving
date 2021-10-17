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

    def preorder(node='A'):
        if node != '.':
            print(node, end='')
            preorder(tree[node][0])
            preorder(tree[node][1])
    
    preorder()
    print()

    def inorder(node='A'):
        if node != '.':
            inorder(tree[node][0])
            print(node, end='')
            inorder(tree[node][1])
        
    inorder()
    print()

    def postorder(node='A'):
        if node != '.':
            postorder(tree[node][0])
            postorder(tree[node][1])
            print(node, end='')

    postorder()
    print()

run()


from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    Input format
    X

    params:
        X  a word     (Non-space, [A-Z], len(X) < 100)

    """
    X = list(stdin.readline().rstrip())

    return X


def solve():
    X = inputs()

    def next_permute(arr):
        i = len(arr) - 2
        while i >= 0 and arr[i] >= arr[i + 1]:
            i -= 1

        if i < 0:
            return None

        j = len(arr) - 1
        while arr[i] >= arr[j]:
            j -= 1

        arr[i], arr[j] = arr[j], arr[i]
        result = arr[: i + 1]
        result.extend(list(reversed(arr[i + 1 :])))
        return result

    answer = next_permute(X)
    if answer is None:
        answer = X

    print("".join(answer))


run(testcase=int(input()))

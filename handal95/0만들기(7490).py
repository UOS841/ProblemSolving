def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N = int(input())

    return N


def solve():
    N = inputs()

    nums = [str(i + 1) for i in range(N)]

    expression = list()
    operation = ["+", "-", " "]
    answers = list()

    def dfs(depth):
        expression.append(nums[depth])

        if depth == N - 1:
            cal_expression = "".join(expression[:])
            answer = eval(cal_expression.replace(" ", ""))
            if answer == 0:
                answers.append(cal_expression)
            return

        for i in range(3):
            expression.append(operation[i])
            dfs(depth + 1)
            expression.pop()
            expression.pop()

    dfs(0)

    answers.sort()
    for answer in answers:
        print(answer)
    print()


run(int(input()))

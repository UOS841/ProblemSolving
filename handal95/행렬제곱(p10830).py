def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    N, B = map(int, input().split())
    matrix = list(list(map(int, input().split())) for _ in range(N))

    return N, B, matrix


def solve():
    N, B, matrix = inputs()
    for r in range(N):
        for c in range(N):
            matrix[r][c] %= 1000

    def product(mat_x, mat_b):
        matrix = [[0] * N for _ in range(N)]
        for r in range(N):
            for c in range(N):
                for i in range(N):
                    matrix[r][c] += mat_x[r][i] * mat_b[i][c]
                matrix[r][c] %= 1000

        return matrix

    def divide(b, matrix):
        if b == 1:
            return matrix

        if b % 2 == 0:
            temp = divide(b // 2, matrix)
            return product(temp, temp)
        else:
            temp = divide(b - 1, matrix)
            return product(temp, matrix)

    answer = divide(B, matrix)
    for row in answer:
        print(*row)


run()

from codeforce_utils import inp


def solve_single():
    n = inp()
    moves = 0
    for i in range(n, 1, -1):
        moves += (n // 2) * (n * n - (n - 1) * (n - 1))
        n -= 1
    return moves


def solve():
    n = inp()
    for i in range(n):
        print(solve_single())


if __name__ == "__main__":
    solve()

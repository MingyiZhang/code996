from codeforce_utils import inp, int_lst


def solve_single():
    a, b, c = int_lst()
    d = abs(a - b)
    total = 2 * d
    if total < a or total < b or total < c:
        return -1
    return c - d if c > d else c + d


def solve():
    n = inp()
    for i in range(n):
        print(solve_single())


if __name__ == "__main__":
    solve()

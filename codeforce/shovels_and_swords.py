from codeforce_utils import inp, int_lst


def count(a, b):
    if a == 0 or b == 0 or (a < 2 and b < 2):
        return 0
    if a > b:
        return count(a - 2, b - 1) + 1
    else:
        return count(a - 1, b - 2) + 1


def solve_single():
    a, b = int_lst()
    return count(a, b)


def solve():
    n = inp()
    for i in range(n):
        print(solve_single())


if __name__ == "__main__":
    solve()

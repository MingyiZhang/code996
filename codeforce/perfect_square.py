def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def str_lst():
    return input().split()


def int_lst_split():
    return map(int, input().split())


def solve_single():
    # abba
    # bcbb
    # bccb
    # abba

    # (0, 0), (0, 3), (3, 0), (3, 3)
    # (0, 1), (1, 3), (2, 0), (3, 2)
    # (x, y), (n - x, n - y),
    # (0, 2), (3, 1)



def solve():
    for i in range(inp()):
        solve_single()


if __name__ == "__main__":
    solve()

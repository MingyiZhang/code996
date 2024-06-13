def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve_single():
    n, m = int_lst()
    aa = int_lst()
    bb = ['B' for _ in range(m)]
    for a in aa:
        mi, ma = min(a, m + 1 - a) - 1, max(a, m + 1 - a) - 1
        if bb[mi] == 'B':
            bb[mi] = 'A'
        else:
            bb[ma] = 'A'
    print("".join(bb))


def solve():
    for _ in range(inp()):
        solve_single()


if __name__ == "__main__":
    solve()

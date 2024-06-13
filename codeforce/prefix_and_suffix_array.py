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
    n = inp()
    fixes = str_lst()
    longest = []
    shortest = []
    for x in fixes:
        if len(x) == n - 1:
            longest.append(x)
        if len(x) == 1:
            shortest.append(x)
    if shortest[0] != shortest[1]:
        print("NO")
    ps = shortest[0]
    pl = longest[0]
    s = ""
    if pl[0] != ps:
        s = shortest[0] + pl
    elif pl[-1] != ps:
        s = pl + shortest[0]
    else:




    if pl[0] == ps:
        s = pl + shortest[1]
    elif pl[0] != ps:
        s = ps + pl



def solve():
    for i in range(inp()):
        solve_single()


if __name__ == "__main__":
    solve()

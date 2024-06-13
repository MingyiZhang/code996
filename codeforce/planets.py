def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve_single():
    n, c = int_lst()
    aa = int_lst()
    a_to_count = {}
    for a in aa:
        if a not in a_to_count:
            a_to_count[a] = 0
        a_to_count[a] += 1
    cost = 0
    for a, count in a_to_count.items():
        if count > c:
            cost += c
        else:
            cost += count
    print(cost)


def solve():
    for i in range(inp()):
        solve_single()


if __name__ == "__main__":
    solve()

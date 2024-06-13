def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve():
    n, a, b = int_lst()
    hh = int_lst()
    hh.sort()
    print(hh[b] - hh[b - 1])

if __name__ == "__main__":
    solve()
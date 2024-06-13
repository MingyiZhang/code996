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


def solve():
    n = inp()
    if n % 2 != 0:
        print(0)
        return
    k = n / 2
    if k % 2 != 0:
        print(int(k // 2))
    else:
        print(int((k / 2) - 1))


if __name__ == "__main__":
    solve()

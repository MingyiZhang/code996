def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve():
    n, k = int_lst()
    ss = c_lst()
    if k <= (n + 1) / 2:
        for i in range(k - 1):
            print("LEFT")
        for i, s in enumerate(ss):
            print("PRINT", s)
            if i != n - 1:
                print("RIGHT")
    else:
        for i in range(n - k):
            print("RIGHT")
        for i, s in enumerate(reversed(ss)):
            print("PRINT", s)
            if i != n - 1:
                print("LEFT")

if __name__ == "__main__":
    solve()
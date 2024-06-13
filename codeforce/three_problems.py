def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())


def solve():
    n = inp()
    rr = int_lst()
    s = dict()
    for i, r in enumerate(rr):
        if r not in s:
            s[r] = i + 1
        if len(s) == 3:
            break
    if len(s) == 3:
        for key in sorted(s.keys()):
            print(s[key], end=" ")
    else:
        print("-1 -1 -1")



if __name__ == "__main__":
    solve()
def inp():
    return int(input())


def int_lst():
    return list(map(int, input().split()))


def c_lst():
    return list(input())


def int_lst_split():
    return map(int, input().split())

import math

def solve_single():
    x, y = int_lst_split()
    c = 0
    while x <= y:
        p = int(math.log10(y / x))
        y -= x * 10 ** p
        c += 1
    if x > y:
        print(c + y)


def solve():
    n = inp()
    for _ in range(n):
        solve_single()



if __name__ == "__main__":
    solve()
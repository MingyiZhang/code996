from codeforce_utils import int_lst
import math


def solve():
    n, m = int_lst()
    aas = int_lst()
    max_r = 0
    ans = 0
    for i, v in enumerate(aas):
        r = math.ceil(v / m)
        if r >= max_r:
            max_r = r
            ans = i + 1
    print(ans)


if __name__ == "__main__":
    solve()
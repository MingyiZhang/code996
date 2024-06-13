from codeforce_utils import int_lst


def comb2(x):
    return x * (x - 1) // 2


def cal_k_min(n, m):
    div = n // m
    mod = n % m
    return mod * comb2(div + 1) + (m - mod) * comb2(div)


def solve():
    n, m = int_lst()
    k_max = comb2(n - m + 1)
    k_min = cal_k_min(n, m)
    print(f"{k_min} {k_max}")


if __name__ == "__main__":
    solve()

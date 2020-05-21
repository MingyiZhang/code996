from typing import List


def max_profit(prices: List[int]) -> int:
    lowest = float('inf')
    ret = 0
    for p in prices:
        if p > lowest:
            ret = max(ret, p - lowest)
        else:
            lowest = p
    return ret


if __name__ == '__main__':
    assert (5 == max_profit([7, 1, 5, 3, 6, 4]))
    assert (0 == max_profit([7, 6, 4, 3, 1]))

from typing import List


def max_profit(prices: List[int]) -> int:
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            profit += prices[i] - prices[i - 1]
    return profit


if __name__ == '__main__':
    assert (7 == max_profit([7, 1, 5, 3, 6, 4]))
    assert (0 == max_profit([7, 6, 4, 3, 1]))
    assert (4 == max_profit([1, 2, 3, 4, 5]))

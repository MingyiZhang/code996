from math import sqrt

"""
a <= b
c = a^2 + b^2 <= 2 b^2

sqrt(c / 2) <= b <= sqrt(c) 
"""


def judge_square_sum(c: int) -> bool:
    for i in range(int(sqrt(c / 2)), int(sqrt(c)) + 1):
        j = c - i * i
        k = int(sqrt(j))
        if k * k == j:
            return True
    return False


if __name__ == '__main__':
    assert(judge_square_sum(5))
    assert(not judge_square_sum(3))
    assert(judge_square_sum(4))
    assert(judge_square_sum(2))
    assert(judge_square_sum(16))

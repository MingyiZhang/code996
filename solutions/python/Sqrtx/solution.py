def my_sqrt(x: int) -> int:
    if x <= 1:
        return x
    left, right = 1, x
    while left <= right:
        mid = left + (right - left) // 2
        sqrt = x // mid
        if sqrt == mid:
            return sqrt
        elif sqrt < mid:
            right = mid - 1
        else:
            left = mid + 1
    return right


if __name__ == '__main__':
    assert (2 == my_sqrt(4))
    assert (2 == my_sqrt(8))

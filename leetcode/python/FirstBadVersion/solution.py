def is_bad_version(version):
    return version > 3


def first_bad_version(n: int) -> int:
    left, right = 1, n
    while left < right:
        mid = (left + right) // 2
        if is_bad_version(mid):
            right = mid
        else:
            left = mid + 1
    return left


if __name__ == '__main__':
    assert(4 == first_bad_version(10))

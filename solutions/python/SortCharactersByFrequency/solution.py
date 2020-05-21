from collections import Counter


def frequency_sort(s: str) -> str:
    cnt = Counter(s).most_common()
    ret = []
    for pair in cnt:
        ret += [pair[0]] * pair[1]
    return ''.join(ret)


if __name__ == '__main__':
    assert('eetr' == frequency_sort("tree"))
    assert('cccaaa' == frequency_sort('cccaaa'))
    assert('bbAa' == frequency_sort('Aabb'))


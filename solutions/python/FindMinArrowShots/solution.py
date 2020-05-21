from typing import List


def find_min_arrow_shots(points: List[List[int]]) -> int:
    if not points:
        return 0

    #  sort intervals
    points.sort(key=lambda x: x[1])
    cnt = 0
    end = -float('inf')
    for p in points:
        if p[0] > end:
            cnt += 1
            end = p[1]
    return cnt


if __name__ == '__main__':
    assert (2 == find_min_arrow_shots([[10, 16], [2, 8], [1, 6], [7, 12]]))
    assert (2 == find_min_arrow_shots([[-1, 1], [0, 1], [2, 3], [1, 2]]))

from typing import List


def is_overlap(itv1: List[int], itv2: List[int]) -> bool:
    return itv1[0] < itv2[1] and itv1[1] > itv2[0]


def erase_overlap_intervals(intervals: List[List[int]]) -> int:
    # cnt = 0
    # end = -float('inf')
    # for itv in sorted(intervals, key=lambda x: x[1]):
    #     if itv[0] < end:
    #         cnt += 1
    #     else:
    #         end = itv[1]
    # return cnt

    if not intervals:
        return 0

    intervals.sort(key=lambda x: x[1])
    cnt = 0
    end = intervals[0][1]
    for i in range(1, len(intervals)):
        if intervals[i][0] < end:
            cnt += 1
        else:
            end = intervals[i][1]
    return cnt


if __name__ == '__main__':
    assert (1 == erase_overlap_intervals([[1, 2], [2, 3], [3, 4], [1, 3]]))
    assert (2 == erase_overlap_intervals([[1, 2], [1, 2], [1, 2]]))
    assert (0 == erase_overlap_intervals([[1, 2], [2, 3]]))
    assert (2 == erase_overlap_intervals([[0, 2], [1, 3], [2, 4], [3, 5], [4, 6]]))

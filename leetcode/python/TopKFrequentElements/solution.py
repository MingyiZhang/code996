from typing import List


def top_k_frequent(nums: List[int], k: int) -> List[int]:
    freq = dict()
    for num in nums:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    freq_list = list()
    for key, val in freq.items():
        freq_list.append([key, val])
    freq_list.sort(key=lambda x: x[1], reverse=True)
    return [x[0] for x in freq_list[:k]]

    # one line solution
    # from collections import Counter
    # return [v[0] for v in Counter(nums).most_common(k)]


if __name__ == '__main__':
    assert([1, 2] == top_k_frequent([1, 1, 1, 2, 2, 3], 2))
    assert([1] == top_k_frequent([1], 1))

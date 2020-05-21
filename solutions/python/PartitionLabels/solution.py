from typing import List


def partition_labels(S: str) -> List[int]:
    # # first solution
    # # get intervals
    # alphabet = dict()
    # for i, c in enumerate(S):
    #     if c in alphabet and alphabet[c][1] < i:
    #         alphabet[c][1] = i
    #     else:
    #         alphabet[c] = [i, i]
    #
    # intervals = [itv for _, itv in alphabet.items()]
    # # sort by start
    # intervals.sort(key=lambda itv: itv[0])
    #
    # ans = []
    # end = intervals[0][1]
    # prev = 0
    # for i in range(1, len(intervals)):
    #     if end < intervals[i][0]:
    #         ans.append(end + 1 - prev)
    #         prev = end + 1
    #     end = max(end, intervals[i][1])
    # ans.append(end + 1 - prev)
    # return ans

    # second solution
    # get ends
    ends = {c: i for i, c in enumerate(S)}
    #
    ans = []
    start = 0
    prev = 0
    while start < len(S):
        end = ends[S[start]]
        while start < end:
            start += 1
            end = max(end, ends[S[start]])
        start += 1
        ans.append(start - prev)
        prev = start
    return ans


if __name__ == '__main__':
    assert([9, 7, 8] == partition_labels('ababcbacadefegdehijhklij'))
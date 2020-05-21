from time import time
from typing import List


# interesting problem
def reconstruct_queue(people: List[List[int]]) -> List[List[int]]:
    people.sort(key=lambda x: (-x[0], x[1]))
    ans = []
    for p in people:
        ans.insert(p[1], p)
    return ans

    #  slow version
    # people.sort(key=lambda x: x[0])
    # ans = [list()] * len(people)
    # for p in people:
    #     cnt = 0
    #     for i, a in enumerate(ans):
    #         if not a and cnt == p[1]:
    #             ans[i] = p
    #             break
    #         if not a or a[0] == p[0]:
    #             cnt += 1
    # return ans


# insert lowest first
def reconstruct_queue_lowest_first(people: List[List[int]]) -> List[List[int]]:
    people.sort(key=lambda x: (x[0], -x[1]))
    pos = list(range(len(people)))
    ans = [list()] * len(people)
    for p in people:
        k = p[1]
        ans[pos[k]] = p
        del pos[k]
    return ans


if __name__ == '__main__':
    N = 1000000
    t0 = time()
    for i in range(N):
        assert ([[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] == reconstruct_queue(
            [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]))
    t1 = time()
    for i in range(N):
        assert ([[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] == reconstruct_queue_lowest_first(
            [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]))
    t2 = time()
    print(f'{t1 - t0}, {t2 - t1}')

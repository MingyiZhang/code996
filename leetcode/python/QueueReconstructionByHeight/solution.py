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


if __name__ == '__main__':
    assert ([[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] == reconstruct_queue(
        [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]))

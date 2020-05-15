from typing import List


def dfs(i: int, M: List[List[int]]):
    M[i][i] = 0
    for j in range(len(M)):
        if M[i][j] == 1:
            M[i][j] = 0
            M[j][i] = 0
            dfs(j, M)


def find_circle_num(M: List[List[int]]) -> int:
    if len(M) == 0:
        return 0

    ret = 0
    for i in range(len(M)):
        if M[i][i] == 1:
            dfs(i, M)
            ret += 1
    return ret

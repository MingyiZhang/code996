from typing import List


dirs = [[0, -1], [0, 1], [-1, 0], [1, 0]]


def max_area(i: int, j: int, I: int, J: int, grid: List[List[int]]) -> int:
    if i < 0 or i >= I or j < 0 or j >= J or grid[i][j] == 0:
        return 0
    area = 1
    grid[i][j] = 0
    for d in dirs:
        area += max_area(i + d[0], j + d[1], I, J, grid)
    return area


def max_area_of_island(grid: List[List[int]]) -> int:
    ret = 0
    if len(grid) == 0:
        return 0
    I, J = len(grid), len(grid[0])
    for i in range(I):
        for j in range(J):
            if grid[i][j] != 0:
                ret = max(ret, max_area(i, j, I, J, grid))
    return ret

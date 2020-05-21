from typing import List


def shortest_path_binary_matrix(grid: List[List[int]]) -> int:
    n = len(grid)
    if not n or grid[0][0] or grid[n - 1][n - 1]:
        return -1
    if n == 1:
        return 1
    q = [[0, 0]]
    grid[0][0] = 1
    path_length = 1
    while len(q):
        path_length += 1
        q_size = len(q)
        while q_size:
            p = q.pop(0)
            q_size -= 1
            x = p[0]
            y = p[1]
            for i in [-1, 0, 1]:
                for j in [-1, 0, 1]:
                    if i == 0 and j == 0:
                        continue
                    xd = x + i
                    yd = y + j
                    if xd == n - 1 and yd == n - 1:
                        return path_length
                    if -1 < xd < n and -1 < yd < n and not grid[xd][yd]:
                        grid[xd][yd] = 1
                        q.append([xd, yd])
    return -1


if __name__ == '__main__':
    assert(2 == shortest_path_binary_matrix([[0, 1], [1, 0]]))
    assert(4 == shortest_path_binary_matrix([[0, 0, 0], [1, 1, 0], [1, 1, 0]]))
    assert(1 == shortest_path_binary_matrix([[0]]))

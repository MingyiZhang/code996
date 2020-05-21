from typing import List


dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]


def dfs(i: int, j: int, I: int, J: int, board: List[List[str]]) -> None:
    if i < 0 or i >= I or j < 0 or j >= J or board[i][j] != 'O':
        return
    board[i][j] = 'B'
    for d in dirs:
        dfs(i + d[0], j + d[1], I, J, board)


def solve(board: List[List[str]]) -> None:
    if len(board) == 0:
        return
    I, J = len(board), len(board[0])
    for i in range(I):
        if board[i][0] == 'O':
            dfs(i, 0, I, J, board)
        if board[i][J - 1] == 'O':
            dfs(i, J - 1, I, J, board)
    for j in range(1, J - 1):
        if board[0][j] == 'O':
            dfs(0, j, I, J, board)
        if board[I - 1][j] == 'O':
            dfs(I - 1, j, I, J, board)

    for i in range(I):
        for j in range(J):
            if board[i][j] == 'O':
                board[i][j] = 'X'
            elif board[i][j] == 'B':
                board[i][j] = 'O'

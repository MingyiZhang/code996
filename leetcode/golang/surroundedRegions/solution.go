package main


var (
  dx = []int{0, 0, 1, -1}
  dy = []int{1, -1, 0, 0}
)

func dfs(i, j, I, J int, board [][]byte) {
  if i < 0 || i >= I || j < 0 || j >= J || board[i][j] != 'O' {
    return
  }
  board[i][j] = 'B'
  for k := 0; k < 4; k++ {
    dfs(i + dx[k], j + dy[k], I, J, board)
  }
}


func solve(board [][]byte) {
  if len(board) == 0 {
    return
  }
  I, J := len(board), len(board[0])
  for i := 0; i < I; i++ {
    dfs(i, 0, I, J, board)
    dfs(i, J - 1, I, J, board)
  }
  for j := 1; j < J - 1; j++ {
    dfs(0, j, I, J, board)
    dfs(I - 1, j, I, J, board)
  }

  for i := 0; i < I; i++ {
    for j := 0; j < J; j++ {
      if board[i][j] == 'O' {
        board[i][j] = 'X'
      } else if board[i][j] == 'B' {
        board[i][j] = 'O'
      }
    }
  }
}
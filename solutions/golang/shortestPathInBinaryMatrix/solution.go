package main

func shortestPathBinaryMatrix(grid [][]int) int {
  N := len(grid)
  if N == 0 || grid[0][0] == 1 || grid[N-1][N-1] == 1 {
    return -1
  }
  if N == 1 {
    return 1
  }
  dirs := [8][2]int{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
  }
  q := [][2]int{
    {0, 0},
  }
  grid[0][0] = 1
  pathLength := 1
  for len(q) > 0 {
    pathLength++
    qSize := len(q)
    for qSize > 0 {
      qSize--
      p := q[0]
      q = q[1:]
      for _, d := range dirs {
        x := p[0] + d[0]
        y := p[1] + d[1]
        if x == y && y == N - 1 {
          return pathLength
        }
        if x > -1 && x < N && y > -1 && y < N && grid[x][y] == 0 {
          q = append(q, [2]int{x, y})
          grid[x][y] = 1
        }
      }
    }
  }
  return -1
}

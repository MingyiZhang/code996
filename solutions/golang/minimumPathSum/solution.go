package main

import "math"

func minPathSum(grid [][]int) int {
  if len(grid) == 0 {
    return 0
  }

  m := len(grid)
  n := len(grid[0])
  v := make([][]int, m)
  for i := 0; i < m; i++ {
    for j := 0; j < n; j++ {
      v[i] = append(v[i], math.MaxInt32)
    }
  }
  v[0][0] = grid[0][0]
  for i := 0; i < m; i++ {
    for j := 0; j< n; j++ {
      if i > 0 {
        v[i][j] = min(v[i][j], v[i - 1][j] + grid[i][j])
      }
      if j > 0 {
        v[i][j] = min(v[i][j], v[i][j - 1] + grid[i][j])
      }
    }
  }
  return v[m - 1][n - 1]
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}
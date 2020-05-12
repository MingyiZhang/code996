package main

var dirs = [][]int{
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1},
}

func maxArea(i int, j int, I int, J int, grid [][]int) int {
  if i < 0 || i >= I || j < 0 || j >= J || grid[i][j] == 0 {
    return 0
  }
  area := 1
  grid[i][j] = 0
  for _, d := range dirs {
    area += maxArea(i + d[0], j + d[1], I, J, grid)
  }
  return area
}

func maxAreaOfIsland(grid [][]int) int {
  if len(grid) == 0 {
    return 0
  }
  ret := 0
  I, J := len(grid), len(grid[0])
  for i := 0; i < I; i++ {
    for j := 0; j < J; j++ {
      if grid[i][j] == 1 {
        area := maxArea(i, j, I, J, grid)
        if area > ret {
          ret = area
        }
      }
    }
  }
  return ret
}

package main

func dfs(i int, M [][]int, visited []bool) {
  visited[i] = true
  for j := 0; j < len(M); j++ {
    if !visited[j] && M[i][j] == 1 {
      visited[j] = true
      dfs(j, M, visited)
    }
  }
}



func findCircleNum(M [][]int) int {
  if len(M) == 0 {
    return 0
  }
  ret := 0
  visited := make([]bool, len(M))
  for i := 0; i < len(M); i++ {
    if !visited[i] {
      dfs(i, M, visited)
      ret++
    }
  }
  return ret
}
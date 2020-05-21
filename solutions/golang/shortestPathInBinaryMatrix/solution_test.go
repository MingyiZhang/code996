package main

import "testing"

func TestShortestPathBinaryMatrix(t *testing.T) {
  tests := []struct {
    grid [][]int
    ans int
  } {
    {[][]int{{0, 1}, {1, 0}}, 2},
    {[][]int{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}, 4},
  }

  for _, tt := range tests {
    actual := shortestPathBinaryMatrix(tt.grid)
    if actual != tt.ans {
      t.Errorf("got %d for input %v; expected %d",
        actual, tt.grid, tt.ans)
    }
  }
}

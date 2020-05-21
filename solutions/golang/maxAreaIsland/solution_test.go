package main

import "testing"

func TestMaxAreaOfIsland(t *testing.T) {
  tests := []struct {
    grid [][]int
    ans  int
  }{
    {
      grid: [][]int{{0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}},
      ans: 3,
    },
    {
      grid: [][]int{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}},
      ans: 6,
    },
    {
      grid: [][]int{{0, 0, 0, 0, 0, 0, 0, 0}},
      ans:  0,
    },
  }

  for _, tt := range tests {
    actual := maxAreaOfIsland(tt.grid)
    if tt.ans != actual {
      t.Errorf("got %d; expected %d with input %v", actual, tt.ans, tt.grid)
    }
  }
}

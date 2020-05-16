package main

import "testing"

func TestFindCircleNum(t *testing.T) {
  tests := []struct {
    M        [][]int
    expected int
  }{
    {
      M: [][]int{{1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}},
      expected: 2,
    }, {
      M: [][]int{{1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}},
      expected: 1,
    }, {
      M: [][]int{{1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}},
      expected: 1,
    },
  }
  for _, tt := range tests {
    actual := findCircleNum(tt.M)
    if tt.expected != actual {
      t.Errorf("expected %d with input %v; got %d", tt.expected, tt.M, actual)
    }
  }
}

package main

import (
  "testing"

  "github.com/stretchr/testify/assert"
)

func TestMinPathSum(t *testing.T) {
  tests := []struct {
    grid     [][]int
    expected int
  }{
    {
      grid:     [][]int{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
      expected: 7,
    },
  }
  for _, tt := range tests {
    assert.Equal(t, tt.expected, minPathSum(tt.grid))
  }
}

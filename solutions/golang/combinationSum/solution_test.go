package main

import (
  "testing"

  "github.com/stretchr/testify/assert"
)

func TestCombinationSum(t *testing.T) {
  tests := []struct {
    candidates []int
    target     int
    expected   [][]int
  }{
    {
      candidates: []int{2, 3, 6, 7},
      target:     7,
      expected:   [][]int{{2, 2, 3}, {7}},
    }, {
      candidates: []int{2, 3, 5},
      target:     8,
      expected:   [][]int{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}},
    },
  }
  for _, tt := range tests {
    actual := combinationSum(tt.candidates, tt.target)
    assert.ElementsMatchf(t, actual, tt.expected, "got %v, expected %v", actual, tt.expected)
  }
}

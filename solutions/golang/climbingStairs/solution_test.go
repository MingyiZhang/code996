package main

import (
  "testing"

  "github.com/stretchr/testify/assert"
)

func TestClimbStairs(t *testing.T) {
  tests := []struct{
    n int
    expected int
  } {
    {
      n: 2,
      expected: 2,
    }, {
      n: 3,
      expected: 3,
    },
  }
  for _, tt := range tests {
    actual := climbStairs(tt.n)
    assert.Equal(t, tt.expected, actual)
  }
}
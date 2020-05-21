package main

import "testing"

func TestMaxSubArray(t *testing.T) {
  tests := []struct {
    nums []int
    ans  int
  }{
    {
      nums: []int{-2, 1, -3, 4, -1, 2, 1, -5, 4},
      ans:  6,
    },
    {
      nums: []int{-2},
      ans:  -2,
    },
  }
  for _, tt := range tests {
    actual := maxSubArray(tt.nums)
    if actual != tt.ans {
      t.Errorf("got %d for input %v; expected %d",
        actual, tt.nums, tt.ans)
    }
  }
}

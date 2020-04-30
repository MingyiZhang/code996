package main

import "testing"

func TestTwoSumII(t *testing.T) {
  tests := []struct {
    numbers []int
    target  int
    ans     []int
  }{
    {[]int{2, 7, 9, 11}, 9, []int{1, 2}},
  }

  for _, tt := range tests {
    actual := twoSumII(tt.numbers, tt.target)
    if actual[0] != tt.ans[0] || actual[1] != tt.ans[1] {
      t.Errorf("got %v for numbers %v and target %d; expected %v",
        actual, tt.numbers, tt.target, tt.ans)
    }
  }
}

package main

import "testing"

func TestMaxProfit(t *testing.T) {
  tests := []struct {
    prices []int
    ans int
  } {
    {
      prices: []int{7, 1, 5, 3, 6, 4},
      ans: 7,
    },
    {
      prices: []int{1, 2, 3, 4, 5},
      ans: 4,
    },
    {
      prices: []int{7, 6, 4, 3, 1},
      ans: 0,
    },
  }
  for _, tt := range tests {
    actual := maxProfit(tt.prices)
    if tt.ans != actual {
      t.Errorf("got %d for input %v; expected %d",
        actual, tt.prices, tt.ans)
    }
  }
}

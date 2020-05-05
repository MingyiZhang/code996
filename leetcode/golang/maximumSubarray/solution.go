package main

func maxSubArray(nums []int) int {
  cSum, mSum := 0, 0
  for i, v := range nums {
    cSum += v
    if cSum > mSum || i == 0 {
      mSum = cSum
    }
    if cSum < 0 {
      cSum = 0
    }
  }
  return mSum
}
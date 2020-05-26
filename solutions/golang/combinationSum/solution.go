package main

import (
  "sort"
)

func backtracking(prefix []int, preSum int, candidates []int, index, target int, ret [][]int) [][]int {
  if preSum == target && len(prefix) != 0 {
    result := make([]int, len(prefix))
    copy(result, prefix)
    return append(ret, result)
  }

  for i := index; i < len(candidates); i++ {
    if preSum + candidates[i] <= target {
      preSum += candidates[i]
      prefix = append(prefix, candidates[i])
      ret = backtracking(prefix, preSum, candidates, i, target, ret)
      prefix = prefix[:len(prefix) - 1]
      preSum -= candidates[i]
    } else {
      break
    }
  }
  return ret
}

func combinationSum(candidates []int, target int) [][]int {
  sort.Ints(candidates)
  var ret [][]int
  var prefix []int
  return backtracking(prefix, 0, candidates, 0, target, ret)
}
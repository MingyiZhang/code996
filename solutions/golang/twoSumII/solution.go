package main

func twoSumII(numbers []int, target int) []int {
  i, j, sum := 0, len(numbers)-1, 0
  for i < j {
    sum = numbers[i] + numbers[j]
    if sum == target {
      return []int{i + 1, j + 1}
    } else if sum < target {
      i++
    } else { // sum > target
      j--
    }
  }
  return []int{0, 0}
}

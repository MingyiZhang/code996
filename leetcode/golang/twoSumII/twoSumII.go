package main

import "fmt"

func twoSumII(numbers []int, target int) []int {
  i, j, sum := 0, len(numbers) - 1, 0
  for i < j {
    sum = numbers[i] + numbers[j]
    if sum == target {
      return []int{i + 1, j + 1}
    } else if sum < target {
      i++
    } else {  // sum > target
      j--
    }
  }
  return []int{0, 0}
}

func main() {
  numbers := []int{2, 7, 9, 11}
  target := 9
  result := twoSumII(numbers, target)
  if result[0] != 1 {
    fmt.Println("Wrong result")
  }
  if result[1] != 2 {
    fmt.Println("Wrong result")
  }
}

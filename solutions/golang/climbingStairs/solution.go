package main

func climbStairs(n int) int {
  if n <= 2 {
    return n
  }
  a := 1
  b := 2
  i := 3
  var ret int
  for i <= n {
    ret = a + b
    a = b
    b = ret
    i++
  }
  return ret
}
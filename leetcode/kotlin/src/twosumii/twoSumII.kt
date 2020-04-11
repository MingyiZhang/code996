package twosumii

fun twoSum(numbers: IntArray, target: Int): IntArray {
  var i = 0
  var j = numbers.size - 1
  var sum: Int
  while (i < j) {
    sum = numbers[i] + numbers[j]
    when {
      sum == target -> return intArrayOf(i + 1, j + 1)
      sum < target -> i++
      else -> j--
    }
  }
  return intArrayOf(0, 0)
}


fun main() {
  val numbers = intArrayOf(2, 7, 9, 11)
  val target = 9
  val result = twoSum(numbers, target)
  assert(result[0] == 1)
  assert(result[1] == 2)
}
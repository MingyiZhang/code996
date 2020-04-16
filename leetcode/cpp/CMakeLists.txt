cmake_minimum_required(VERSION 3.15)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

macro(ADD_EXE NAME)
  add_executable(${NAME}.out ${NAME}/solution.cpp)
endmacro()

add_exe(twoSumII)
add_exe(sumOfSquareNumbers)
add_exe(reverseVowels)
add_exe(validPalindrome)

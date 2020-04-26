cmake_minimum_required(VERSION 3.1)
# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall \
  -Wextra -fPIC \
  -Wno-sign-compare \
  -Wno-unused-parameter \
  -Wno-unused-but-set-variable \
  -Wno-unused-variable ")

add_subdirectory(2.AddTwoNums)
add_subdirectory(19.RemoveNthNode)
add_subdirectory(15.ThreeSum)
add_subdirectory(n.FastSort)
add_subdirectory(74.SearchMatrix)
add_subdirectory(240.SearchMatrixII)
add_subdirectory(9.PalindromeNumber)

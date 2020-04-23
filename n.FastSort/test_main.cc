#include <iostream>
#include "solution.hpp"

int main(int, char**) {
  std::vector<int> nums{-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
  FastSortInPlace(nums);
  for (const auto& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}

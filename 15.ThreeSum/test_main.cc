#include <iostream>
#include "solution.hpp"

int main(int, char**) {
  std::vector<int> nums{-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};

  Solution s;
  const auto result = s.threeSum(nums);
  for (const auto& tuple : result) {
    std::cout << "[" << tuple[0] << ", " << tuple[1] << ", " << tuple[2] << "]"
              << std::endl;
  }

  return 0;
}

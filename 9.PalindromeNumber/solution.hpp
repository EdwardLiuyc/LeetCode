#pragma once

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it
reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome. Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/

#include <vector>

static const auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }
    int64_t raw_x = x;
    int64_t new_x = 0;
    while (x > 0) {
      new_x = new_x * 10 + x % 10;
      x /= 10;
    }

    return new_x == raw_x;
  }
};
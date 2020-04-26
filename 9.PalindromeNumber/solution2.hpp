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

#include <iostream>
#include <string>
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

    std::string str = std::to_string(x);
    bool result = true;
    const int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
      if (str[i] != str[len - i - 1]) {
        result = false;
        break;
      }
    }

    return result;
  }
};
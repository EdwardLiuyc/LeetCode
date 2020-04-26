#include <iostream>
#include "solution3.hpp"

int main(int, char**) {
  Solution s;
  std::cout << s.isPalindrome(2343) << " " << s.isPalindrome(1212121)
            << std::endl;
  return 0;
}

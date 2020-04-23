#include <iostream>
#include "solution.hpp"

int main(int, char**) {
  int test_array_1[] = {1, 2, 3, 4, 5};
  const int n = 2;

  ListNode* l1 = nullptr;
  ListNode* current_l1 = nullptr;
  for (int i = 0; i < 5; ++i) {
    ListNode* new_l1 = new ListNode(test_array_1[i]);
    if (!l1) {
      l1 = new_l1;
    }
    if (current_l1) {
      current_l1->next = new_l1;
    }
    current_l1 = new_l1;
  }

  Solution solution;
  auto result = solution.removeNthFromEnd(l1, n);
  while (result) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;

  return 0;
}

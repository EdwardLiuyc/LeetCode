#include <iostream>
#include "solution.hpp"

int main(int, char**) {
  int test_array_1[] = {2, 4, 3};
  int test_array_2[] = {5, 6, 4};

  ListNode* l1 = nullptr;
  ListNode* l2 = nullptr;
  ListNode* current_l1 = nullptr;
  ListNode* current_l2 = nullptr;
  for (int i = 0; i < 3; ++i) {
    ListNode* new_l1 = new ListNode(test_array_1[i]);
    ListNode* new_l2 = new ListNode(test_array_2[i]);
    if (!l1) {
      l1 = new_l1;
    }
    if (!l2) {
      l2 = new_l2;
    }
    if (current_l1) {
      current_l1->next = new_l1;
    }
    if (current_l2) {
      current_l2->next = new_l2;
    }
    current_l1 = new_l1;
    current_l2 = new_l2;
  }

  Solution solution;
  auto result = solution.addTwoNumbers(l1, l2);
  while (result) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;

  return 0;
}
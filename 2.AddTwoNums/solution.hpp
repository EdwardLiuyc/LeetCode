#pragma once

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // no empty, so do not check if l1 or l2 is nullptr
    ListNode* current1 = l1;
    ListNode* current2 = l2;
    int leave = 0;
    ListNode* result = nullptr;
    ListNode* last_node = nullptr;

    while (current1 != nullptr || current2 != nullptr || leave != 0) {
      int val = 0;
      if (current1) {
        val += current1->val;
        current1 = current1->next;
      }
      if (current2) {
        val += current2->val;
        current2 = current2->next;
      }
      val += leave;
      leave = (val > 9 ? 1 : 0);
      const int add_digit = leave ? val - 10 : val;
      ListNode* node = new ListNode(add_digit);
      if (!result) {
        result = node;
      }
      if (last_node) {
        last_node->next = node;
      }
      last_node = node;
    }

    return result;
  }
};
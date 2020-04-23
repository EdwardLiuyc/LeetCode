#pragma once

// Given a linked list, remove the n-th node from the end of list and return its
// head.

// Given n will always be valid.

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool isNthFromTheEnd(ListNode* current, int n) {
    auto temp = current;
    for (int i = 0; i < n; ++i) {
      if (temp->next) {
        temp = temp->next;
      } else if (i == n - 1) {
        return true;
      }
    }
    return false;
  }

  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto current = head;
    ListNode* last_node = head;
    while (current) {
      if (!isNthFromTheEnd(current, n)) {
        last_node = current;
        current = current->next;
        continue;
      }

      if (last_node == current) {
        // it is the head we want to remove
        if (last_node->next) {
          return last_node->next;
        } else {
          return nullptr;
        }
      } else {
        last_node->next = current->next;
        return head;
      }
    }
    return nullptr;
  }
};
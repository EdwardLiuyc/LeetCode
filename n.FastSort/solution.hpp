#pragma once

// fast sort

#include <vector>

void Partition(std::vector<int>& nums, int l, int r) {
  if (l >= r) {
    return;
  }
  if (l + 1 == r) {
    if (nums[l] > nums[r]) {
      std::swap(nums[l], nums[r]);
    }
    return;
  }

  int i = l;
  int j = r;
  int x = nums[l];
  while (i < j) {
    while (i < j && nums[j] > x) --j;
    while (i < j && nums[i] <= x) ++i;
    if (i == j) {
      std::swap(nums[i], nums[l]);
    } else {
      std::swap(nums[i], nums[j]);
    }
  }

  Partition(nums, i + 1, r);
  Partition(nums, l, i - 1);
}

void FastSortInPlace(std::vector<int>& nums) {
  if (nums.size() <= 1) {
    return;
  }
  Partition(nums, 0, nums.size() - 1);
}
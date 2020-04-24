#pragma once

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.
Given target = 20, return false.

*/

#include <queue>
#include <vector>
using std::vector;

class Solution {
 public:
  using Index2d = std::pair<int, int>;

  bool BinarySearch(vector<int>& nums, int& l, int& r, int target) {
    if (l > r) {
      return false;
    }
    if (l == r) {
      return nums[l] == target;
    } else if (l + 1 == r) {
      return nums[l] == target || nums[r] == target;
    }
    const int mid = (l + r) / 2;
    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] < target) {
      l = mid;
      return BinarySearch(nums, l, r, target);
    } else {
      r = mid;
      return BinarySearch(nums, l, r, target);
    }
    return false;
  }

  bool BinarySearch(vector<vector<int>>& matrix, Index2d& l, Index2d& r,
                    int target) {
    if (l.first == r.first) {
      int tmp_l = l.second;
      int tmp_r = r.second;
      return BinarySearch(matrix[l.first], tmp_l, tmp_r, target);
    }
    if (l.second == r.second) {
      std::vector<int> nums;
      for (int i = l.first; i <= r.first; ++i) {
        nums.push_back(matrix[i][l.second]);
      }
      if (nums.empty()) {
        return false;
      }
      int tmp_l = 0;
      int tmp_r = nums.size() - 1;
      return BinarySearch(nums, tmp_l, tmp_r, target);
    }
    if (matrix[l.first][l.second] > target ||
        matrix[r.first][r.second] < target) {
      return false;
    }

    auto mid =
        std::make_pair((l.first + r.first) / 2, (l.second + r.second) / 2);
    auto l_1 = std::make_pair(mid.first + 1, l.second);
    auto r_1 = std::make_pair(r.first, mid.second);

    auto l_2 = std::make_pair(l.first, mid.second + 1);
    auto r_2 = std::make_pair(mid.first, r.second);
    if (matrix[mid.first][mid.second] == target) {
      return true;
    } else if (target > matrix[mid.first][mid.second]) {
      auto l_3 = std::make_pair(mid.first + 1, mid.second + 1);
      auto r_3 = std::make_pair(r.first, r.second);

      return BinarySearch(matrix, l_1, r_1, target) ||
             BinarySearch(matrix, l_2, r_2, target) ||
             BinarySearch(matrix, l_3, r_3, target);
    }
    return BinarySearch(matrix, l_1, r_1, target) ||
           BinarySearch(matrix, l_2, r_2, target) ||
           BinarySearch(matrix, l, mid, target);
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int rows_ = matrix.size();
    if (rows_ == 0) {
      return false;
    }
    const int cols_ = matrix[0].size();
    if (cols_ == 0) {
      return false;
    }
    if (matrix[0][0] > target || matrix[rows_ - 1][cols_ - 1] < target) {
      return false;
    }

    auto l = std::make_pair(0, 0);
    auto r = std::make_pair(rows_ - 1, cols_ - 1);
    return BinarySearch(matrix, l, r, target);
  }
};

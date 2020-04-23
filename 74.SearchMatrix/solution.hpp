#pragma once

#include <vector>
using std::vector;
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous
row.
*/

class Solution {
 public:
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

    std::vector<int> row_start(rows_);
    for (int i = 0; i < rows_; ++i) {
      row_start[i] = matrix[i][0];
    }
    int row_l = 0;
    int row_r = rows_ - 1;
    if (target > row_start[rows_ - 1]) {
      int l = 1;
      int r = cols_ - 1;
      return BinarySearch(matrix[rows_ - 1], l, r, target);
    }
    if (!BinarySearch(row_start, row_l, row_r, target)) {
      // std::cout << row_l << " " << row_r << std::endl;
      int target_line = row_l;
      // if (target >= row_start[row_r]) {
      //   target_line = row_r;
      // }
      int l = 1;
      int r = cols_ - 1;
      return BinarySearch(matrix[target_line], l, r, target);
    }
    return true;
  }
};
#pragma once

/*
Given an array nums of n integers
are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:
The solution set must not contain duplicate triplets.
*/

#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    std::map<std::pair<int, int>, int> result_map;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; ++i) {
      std::set<int> d;
      const int s = -nums[i];
      for (int j = i + 1; j < size; ++j) {
        const int x = s - nums[j];
        if (d.count(x) == 0) {
          d.insert(nums[j]);
        } else {
          result_map[std::make_pair(nums[i], nums[j])] = x;
        }
      }
    }
    vector<vector<int>> result;
    for (auto& t : result_map) {
      result.push_back({t.first.first, t.first.second, t.second});
    }
    return result;
  }
};
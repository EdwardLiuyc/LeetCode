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
  struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
      return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
  };

  vector<vector<int>> threeSum(vector<int>& nums) {
    using Key = std::pair<int, int>;
    int size = nums.size();

    std::sort(nums.begin(), nums.end());

    std::unordered_set<Key, pair_hash> keys;
    std::unordered_map<Key, int, pair_hash> result_in_map;
    for (int i = 1; i < size - 1; ++i) {
      int next_num = nums[i + 1];
      for (int j = 0; j < i; ++j) {
        if (next_num + nums[i] + nums[j] > 0) {
          break;
        }
        std::cout << nums[j] << ", " << nums[i] << ", " << next_num
                  << std::endl;
        auto new_key = std::make_pair(nums[j], nums[i]);
        if (result_in_map.count(new_key)) {
          continue;
        }
        if (next_num + nums[i] + nums[j] == 0) {
          result_in_map[new_key] = next_num;
          continue;
        }
        keys.insert(new_key);
      }

      if (nums[i - 1] + nums[i] + next_num < 0) {
        continue;
      }
      for (auto it = keys.begin(); it != keys.end();) {
        const int sum = it->first + it->second + next_num;
        if (sum == 0) {
          result_in_map[*it] = next_num;
          it = keys.erase(it);
        } else if (sum > 0) {
          it = keys.erase(it);
        } else {
          ++it;
        }
      }
    }
    vector<vector<int>> result;
    for (const auto& tuples : result_in_map) {
      // if (tuples.first.first + tuples.first.second + tuples.second == 0)
      result.push_back(
          {tuples.first.first, tuples.first.second, tuples.second});
    }
    return result;
  }
};
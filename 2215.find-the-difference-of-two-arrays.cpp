/*
 * @lc app=leetcode.cn id=2215 lang=cpp
 * @lcpr version=
 *
 * [2215] 找出两数组的不同
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end()),
        set2(nums2.begin(), nums2.end());
    vector<vector<int>> res(2);
    for (int num : set1) {
      if (!set2.count(num)) {
        res[0].push_back(num);
      }
    }
    for (int num : set2) {
      if (!set1.count(num)) {
        res[1].push_back(num);
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,3]\n[1,1,2,2]\n
// @lcpr case=end

 */

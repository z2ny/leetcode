/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=
 *
 * [4] 寻找两个正序数组的中位数
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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 归并排序
    vector<int> res;
    while (!nums1.empty() && !nums2.empty()) {
      if (nums1.front() < nums2.front()) {
        res.push_back(nums1.front());
        nums1.erase(nums1.begin());
      } else {
        res.push_back(nums2.front());
        nums2.erase(nums2.begin());
      }
    }
    while (!nums1.empty()) {
      res.push_back(nums1.front());
      nums1.erase(nums1.begin());
    }
    while (!nums2.empty()) {
      res.push_back(nums2.front());
      nums2.erase(nums2.begin());
    }
    if (res.size() % 2 == 0) {
      // 2.0是为了防止取整
      return (res[res.size() / 2] + res[res.size() / 2 - 1]) / 2.0;
    } else {
      return res[res.size() / 2];
    }

  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

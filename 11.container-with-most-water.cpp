/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=
 *
 * [11] 盛最多水的容器
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
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    while (left < right) {
      res = max((right - left) * min(height[left], height[right]), res);
      if (height[left] <= height[right])
        left++;
      else
        right--;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=
 *
 * [238] 除自身以外数组的乘积
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
  vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int> left(nums.size(), 1);
    std::vector<int> right(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
      right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = left[i] * right[i];
    }
    return nums;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

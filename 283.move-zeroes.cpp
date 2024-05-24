/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=
 *
 * [283] 移动零
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
  void moveZeroes(vector<int>& nums) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != 0) {
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }
    // for (int i = slow; i < nums.size(); i++) {
    //   nums[i] = 0;
    // }
    std::fill(nums.begin() + slow, nums.end(), 0);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

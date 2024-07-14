/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=
 *
 * [724] 寻找数组的中心下标
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
#include <numeric>
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
  int pivotIndex(vector<int>& nums) {
    int left = 0;
    int right = std::accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++) {
      right -= nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }
    return -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

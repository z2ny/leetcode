/*
 * @lc app=leetcode.cn id=643 lang=cpp
 * @lcpr version=
 *
 * [643] 子数组最大平均数 I
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
  double findMaxAverage(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    while (right < nums.size()) {
      sum += nums[right];
      if (right - left + 1 == k) {
        maxSum = max(maxSum, sum);
        sum -= nums[left];
        left++;
      }
      right++;
    }

    return static_cast<double>(maxSum) / k;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,12,-5,-6,50,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n
// @lcpr case=end

 */

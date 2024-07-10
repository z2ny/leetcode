/*
 * @lc app=leetcode.cn id=334 lang=cpp
 * @lcpr version=
 *
 * [334] 递增的三元子序列
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
  bool increasingTriplet(vector<int>& nums) {
    // 贪心：从左到右遍历，first初始化为nums[0]，second初始化为INT_MAX
    // 如果遇到的num比second大，则返回true
    // 如果遇到的num比first大但比second小，则更新second
    // 如果遇到的num比first小，则更新first
    // 要想找到子序列，first和second一定要尽可能小，并且注意到，我们始终满足：只要后面找到一个比second大的元素，子序列就成立
    int first = nums[0], second = INT_MAX;
    for (int num : nums) {
      if (num > second) return true;
      if (num > first && num < second) second = num;
      if (num < first) first = num;
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,0,4,6]\n
// @lcpr case=end

 */

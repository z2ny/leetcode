/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=
 *
 * [27] 移除元素
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
  int removeElement(vector<int>& nums, int val) {
    int p1 = 0;
    int n = nums.size();
    // 注意：nums.size()是无符号整数，当为空数组时，直接用nums.size()-1不会等于-1，而会溢出
    for (int p2 = 0; p2 <= n - 1; p2++) {
      if (nums[p2] != val) {
        nums[p1] = nums[p2];
        p1++;
      }
    }
    return p1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 * @lcpr version=
 *
 * [1679] K 和数对的最大数目
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
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;
    int res = 0;
    while (left < right) {
      if (nums[left] + nums[right] == k) {
        res++;
        left++;
        right--;
      } else if (nums[left] + nums[right] < k) {
        left++;
      } else {
        right--;
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,3]\n6\n
// @lcpr case=end

 */

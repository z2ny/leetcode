/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=
 *
 * [209] 长度最小的子数组
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
  int minSubArrayLen(int target, vector<int> &nums) {
    //   int res = 0;
    //   for (int i = 0; i < nums.size(); i++) {
    //     int sum = 0;
    //     int offset = 0;
    //     while (offset < nums.size() - i) {
    //       sum += nums[i + offset];
    //       offset++;
    //       if (sum >= target) {
    //         // 如果res此时已经>0，就取min(res, offset)
    //         // 如果res此时=0，就取offset
    //         res = res ? min(res, offset) : offset;
    //         break;
    //       }
    //     }
    //   }
    //   return res;
    // }
    // 上面On^2的时间复杂度 某些case会超时

    // 利用前缀和进行二分搜索，控制复杂度在Onlogn
    // 略//单纯为了节省搜索的时间，需要加入额外前缀和数组以及边界控制的二分查找，没意思

    // 滑动窗口
    int left = 0, right = 0;
    int sum = 0;
    int res = INT_MAX;
    while (right < nums.size()) {
      sum += nums[right];
      while (sum >= target) {
        res = std::min(res, right - left + 1);
        sum -= nums[left];
        left++;
      }
      right++;
    }
    return res == INT_MAX ? 0 : res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
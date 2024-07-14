/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=
 *
 * [1004] 最大连续1的个数 III
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
  int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int zero_num = 0;
    int one_count = 0;
    while (right < nums.size()) {
      if (nums[right] == 1) {
        right++;
      } else if (nums[right] == 0) {
        if(zero_num <2){
            right ++;
        }else if (zero_num ==2){
            left ++;
        }

      }
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=
 *
 * [977] 有序数组的平方
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
  vector<int> sortedSquares(vector<int>& nums) {
    // for (int i = 0; i < nums.size(); i++) {
    //   nums[i] = nums[i] * nums[i];
    //   // 插入排序
    //   int flag = nums[i], j = i - 1;
    //   while (j >= 0 && nums[j] > flag) {
    //     nums[j + 1] = nums[j];
    //     j--;
    //   }
    //   nums[j + 1] = flag;
    // }
    // return nums;

    // 双指针，从左右开始，因为对于非递减数组，每个数字的平方已经是由外向内逐渐减小
    int left = 0, right = nums.size() - 1;
    vector<int> res(nums.size(), 0);
    int i = res.size() - 1;
    while (left <= right) {
      int left_res = nums[left] * nums[left];
      int right_res = nums[right] * nums[right];
      if (left_res <= right_res) {
        res[i] = right_res;
        right--;
      } else {
        res[i] = left_res;
        left++;
      }
      i--;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

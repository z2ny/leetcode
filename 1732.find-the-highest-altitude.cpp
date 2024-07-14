/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 * @lcpr version=
 *
 * [1732] 找到最高海拔
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
  int largestAltitude(vector<int>& gain) {
    vector<int> height(gain.size() + 1, 0);
    int max_h = 0;
    for (int i = 0; i < gain.size(); i++) {
      height[i + 1] = height[i] + gain[i];
      max_h = max(max_h, height[i + 1]);
    }
    return max_h;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-5,1,5,0,-7]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-3,-2,-1,4,3,2]\n
// @lcpr case=end

 */

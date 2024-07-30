/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 * @lcpr version=
 *
 * [2390] 从字符串中移除星号
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
  string removeStars(string s) {
    string res;
    for (auto c : s) {
      if (c != '*')
        res.push_back(c);
      else
        res.pop_back();
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "leet**cod*e"\n
// @lcpr case=end

// @lcpr case=start
// "erase*****"\n
// @lcpr case=end

 */

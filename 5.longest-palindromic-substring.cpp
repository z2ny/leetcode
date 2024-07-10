/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=
 *
 * [5] 最长回文子串
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
  string longestPalindrome(string s) {
    int length = 0;
    int res_left = 0, res_right = 0;
    for (int i = 0; i < s.size(); i++) {
      vector<int> temp1 = expandSubStr(s, i, i);
      vector<int> temp2 = expandSubStr(s, i, i + 1);
      if (temp1[1] - temp1[0] > res_right - res_left) {
        res_left = temp1[0];
        res_right = temp1[1];
      }
      if (temp2[1] - temp2[0] > res_right - res_left) {
        res_left = temp2[0];
        res_right = temp2[1];
      }
    }
    return s.substr(res_left, res_right - res_left + 1);
  }

  // 要考虑到子串长度为奇数和偶数的情况，所以设置开始对比的位置为left和right
  vector<int> expandSubStr(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      right++;
      left--;
    }
    return vector<int>{left + 1, right - 1};
  }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

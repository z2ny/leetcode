/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=
 *
 * [3] 无重复字符的最长子串
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
  int lengthOfLongestSubstring(string s) {
    std::unordered_set<char> keys;
    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
      if (keys.count(s[right]) == 0) {
        keys.insert(s[right]);
        right++;
        res = std::max(res, right - left);
      } else {
        keys.erase(s[left]);
        left++;
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

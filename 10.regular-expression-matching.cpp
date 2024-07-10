/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=
 *
 * [10] 正则表达式匹配
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
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2] ||
                     (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                      dp[i - 1][j]);
        } else {
          dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */

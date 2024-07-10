/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 * @lcpr version=
 *
 * [1071] 字符串的最大公因子
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
#include <math>
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
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
      return "";
    }
    return str1.substr(0, gcd(str1.size(), str2.size()));
  }
};
// @lc code=end

/*
// @lcpr case=start
// "ABCABC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "ABABAB"\n"ABAB"\n
// @lcpr case=end

// @lcpr case=start
// "LEET"\n"CODE"\n
// @lcpr case=end

 */

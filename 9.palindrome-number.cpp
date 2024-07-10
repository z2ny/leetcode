/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=
 *
 * [9] 回文数
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
  bool isPalindrome(int x) {
    std::string str_x = std::to_string(x);
    int i = 0, j = str_x.size() - 1;
    while (i < j) {
      if (str_x[i] != str_x[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

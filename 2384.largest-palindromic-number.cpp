/*
 * @lc app=leetcode.cn id=2384 lang=cpp
 * @lcpr version=
 *
 * [2384] 最大回文数字
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
  string largestPalindromic(string num) {
    int counts[10] = {0};
    for (int i = 0; i < num.size(); i++) {
      counts[num[i] - '0']++;
    }
    std::string res;
    for (int i = 9; i >= 0; i--) {
      while (counts[i] >= 2) {
        res += std::to_string(i);
        counts[i] -= 2;
      }
    }
    res.erase(0, res.find_first_not_of('0'));

    int mid = -1;
    for (int i = 9; i >= 0; i--) {
      if (counts[i] == 1) {
        mid = i;
        break;
      }
    }
    std::string midPart = mid != -1 ? std::to_string(mid) : "";
    res +=midPart + std::string(res.rbegin(), res.rend());
    return res == "" ? "0" : res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "444947137"\n
// @lcpr case=end

// @lcpr case=start
// "00009"\n
// @lcpr case=end

 */

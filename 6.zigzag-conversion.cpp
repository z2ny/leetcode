/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=
 *
 * [6] Z 字形变换
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
#include <numeric>
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
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    vector<string> res(numRows, "");
    int row = 0;
    int convertFlag = -1;
    for (auto c : s) {
      res[row] += c;
      if (row == 0 || row == numRows - 1) convertFlag = -convertFlag;
      row += convertFlag;
    }
    return std::accumulate(res.begin(), res.end(), std::string(""));
  }
};
// @lc code=end

/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

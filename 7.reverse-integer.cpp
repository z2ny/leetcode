/*
 * @lc app=leetcode.cn id=7 lang=cpp
 * @lcpr version=
 *
 * [7] 整数反转
 */

// @lcpr-template-start
using namespace std;
#include <math.h>

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
  int reverse(int x) {
    // int类型的最小值-2^31不能被直接取反,因为int类型的最大值是2^31 -1
    if (x == INT_MIN) return 0;
    if (x < 0) return -reverse(-x);
    long res = 0;
    std::string x_str = std::to_string(x);
    for (int i = 0; i < x_str.length(); i++) {
      res += (x_str[i] - '0') * std::pow(10, i);
    }
    return res > INT_MAX ? 0 : res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 123\n
// @lcpr case=end

// @lcpr case=start
// -123\n
// @lcpr case=end

// @lcpr case=start
// 120\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

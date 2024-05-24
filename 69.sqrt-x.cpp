/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=
 *
 * [69] x 的平方根
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
  double mySqrt(int x) {
    double left = 0, right = x;
    double res = 0;
    while (left <= right) {
      double mid = (left + right) / 2;
      if (mid * mid < x) {
        left = mid;
        res = mid;
      } else if (mid * mid > x) {
        right = mid;
      } else {
        return mid;
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

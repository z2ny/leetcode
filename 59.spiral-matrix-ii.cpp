/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=
 *
 * [59] 螺旋矩阵 II
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
  vector<vector<int>> generateMatrix(int n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    vector<vector<int>> res(n, vector<int>(n));
    int num = 1;
    while (left <= right && top <= bottom) {
      for (int i = left; i <= right; i++) {
        res[top][i] = num++;
      }
      top++;
      if (top > bottom) break;
      for (int i = top; i <= bottom; i++) {
        res[i][right] = num++;
      }
      right--;
      if (left > right) break;
      for (int i = right; i >= left; i--) {
        res[bottom][i] = num++;
      }
      bottom--;
      if (top > bottom) break;
      for (int i = bottom; i >= top; i--) {
        res[i][left] = num++;
      }
      left++;
      if (left > right) break;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

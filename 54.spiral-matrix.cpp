/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=
 *
 * [54] 螺旋矩阵
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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int left = 0, right = matrix[0].size() - 1, top = 0,
        bottom = matrix.size() - 1;
    while (left <= right && top <= bottom) {
      for (int i = left; i <= right; i++) {
        res.push_back(matrix[top][i]);
      }
      top++;
      if (top > bottom) break;
      for (int i = top; i <= bottom; i++) {
        res.push_back(matrix[i][right]);
      }
      right--;
      if (left > right) break;
      for (int i = right; i >= left; i--) {
        res.push_back(matrix[bottom][i]);
      }
      bottom--;
      if (top > bottom) break;
      for (int i = bottom; i >= top; i--) {
        res.push_back(matrix[i][left]);
      }
      left++;
      if (left > right) break;
    }
    return res;
  }
};

// int main() {
//   Solution sol;
//   vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//   auto res = sol.spiralOrder(matrix);
//   for (auto i : res) {
//     cout << i << " ";
//   }
//   cout << endl;
//   return 0;
// }

// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

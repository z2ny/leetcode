/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 * @lcpr version=
 *
 * [2352] 相等行列对
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
#include <map>
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
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> cnt;
    for (auto row : grid) {
      cnt[row]++;
    }

    int res = 0;
    for (int j = 0; j < n; j++) {
      vector<int> arr;
      for (int i = 0; i < n; i++) {
        arr.emplace_back(grid[i][j]);
      }
      if (cnt.find(arr) != cnt.end()) {
        res += cnt[arr];
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,2,1],[1,7,6],[2,7,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]\n
// @lcpr case=end

 */

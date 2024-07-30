/*
 * @lc app=leetcode.cn id=735 lang=cpp
 * @lcpr version=
 *
 * [735] 小行星碰撞
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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (auto aster : asteroids) {
      while (aster < 0 && !st.empty() && st.back() > 0) {
        if (st.back() < -aster) {
          st.pop_back();
        } else if (st.back() == -aster) {
          st.pop_back();
          aster = 0;
          break;
        } else {
          aster = 0;
          break;
        }
      }
      if (aster != 0) {
        st.push_back(aster);
      }
    }
    return st;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,10,-5]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

 */

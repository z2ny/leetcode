/*
 * @lc app=leetcode.cn id=605 lang=cpp
 * @lcpr version=
 *
 * [605] 种花问题
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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int max = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 0) {
        if (i - 1 < 0 || flowerbed[i - 1] == 0) {
          if (i + 1 > flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            max += 1;
          }
        }
      }
    }
    return max >= n;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,0,0,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,1]\n2\n
// @lcpr case=end

 */

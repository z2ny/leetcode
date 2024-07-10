/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 * @lcpr version=
 *
 * [1431] 拥有最多糖果的孩子
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
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int temp = candies[0];
    for (int i = 1; i < candies.size(); i++) {
      temp = max(temp, candies[i]);
    }
    vector<bool> res;
    for (int i = 0; i < candies.size(); i++) {
      res.push_back(candies[i] + extraCandies >= temp);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,5,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,2,1,1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [12,1,12]\n10\n
// @lcpr case=end

 */

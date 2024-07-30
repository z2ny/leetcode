/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 * @lcpr version=
 *
 * [1207] 独一无二的出现次数
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
  bool uniqueOccurrences(vector<int>& arr) {
    std::unordered_map<int, int> count;
    for (auto i : arr) {
      count[i]++;
    }
    std::unordered_set<int> s;
    for (auto& [k, v] : count) {
      if (s.find(v) != s.end()) {
        return false;
      }
      s.insert(v);
    }
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [-3,0,1,-3,1,1,1,-3,10,0]\n
// @lcpr case=end

 */

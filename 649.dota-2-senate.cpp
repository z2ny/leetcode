/*
 * @lc app=leetcode.cn id=649 lang=cpp
 * @lcpr version=
 *
 * [649] Dota2 参议院
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
  string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;
    for (int i = 0; i < n; ++i) {
      if (senate[i] == 'R') {
        radiant.push(i);
      } else {
        dire.push(i);
      }
    }
    while (!radiant.empty() && !dire.empty()) {
      if (radiant.front() < dire.front()) {
        // R如果先于D，一定会ban掉D，同时+n进入队列，作为下一轮投票开始
        radiant.push(radiant.front() + n);
      } else {
        dire.push(dire.front() + n);
      }
      radiant.pop();
      dire.pop();
    }
    return !radiant.empty() ? "Radiant" : "Dire";
  }
};
// @lc code=end

/*
// @lcpr case=start
// "RD"\n
// @lcpr case=end

// @lcpr case=start
// "RDD"\n
// @lcpr case=end

 */

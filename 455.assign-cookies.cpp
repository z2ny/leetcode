/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=
 *
 * [455] 分发饼干
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
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // // 1.大饼干应该优先满足大胃口，因此从最大的饼干和最大胃口开始往下遍历
    // int index = s.size() - 1;
    // int res = 0;
    // for (int i = g.size() - 1; i >= 0; i--) {
    //   if (index >= 0 && s[index] >= g[i]) {
    //     index--;
    //     res++;
    //   }
    // }
    // return res;

    // 2. 小胃口优先，被满足的胃口一定是从小到大中间没有空的
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (index < g.size() && s[i] >= g[index]) index++;
    }
    // 这里最好不要用<=s/g.size()-1 避免g/s为空时报错
    return index;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

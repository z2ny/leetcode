/*
 * @lc app=leetcode.cn id=933 lang=cpp
 * @lcpr version=
 *
 * [933] 最近的请求次数
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
class RecentCounter {
  queue<int> q;

 public:
  RecentCounter() {}

  int ping(int t) {
    q.push(t);
    while (q.front() < t - 3000) {
      q.pop();
    }
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping", "ping"][[], [1], [100], [3001],
[3002]]\n
// @lcpr case=end

 */

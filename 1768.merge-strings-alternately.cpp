/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=
 *
 * [1768] 交替合并字符串
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
  string mergeAlternately(string word1, string word2) {
    string res;
    int i = 0, j = 0;
    while (i < word1.length() && j < word2.length()) {
      res.push_back(word1[i++]);
      res.push_back(word2[j++]);
    }
    while (i < word1.length()) {
      res.push_back(word1[i++]);
    }
    while (j < word2.length()) {
      res.push_back(word2[j++]);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */

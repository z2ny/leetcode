/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 * @lcpr version=
 *
 * [1657] 确定两个字符串是否接近
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
  bool closeStrings(string word1, string word2) {
    // 每一个字符串里面相同字符的数量相等即可
    if (word1.size() != word2.size()) return false;
    // 记录每个字符出现次数
    unordered_map<char, int> m1, m2;
    for (auto c : word1) m1[c]++;
    for (auto c : word2) m2[c]++;
    // 检查两个字符串是否包含相同的字符集
    unordered_set<char> s1(word1.begin(), word1.end());
    unordered_set<char> s2(word2.begin(), word2.end());
    if (s1 != s2) return false;
    // 记录每个出现次数的出现次数
    unordered_map<int, int> n1, n2;
    for (auto [_, v] : m1) n1[v]++;
    for (auto [_, v] : m2) n2[v]++;
    return n1 == n2;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"abbccc"\n
// @lcpr case=end

 */

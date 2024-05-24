/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=
 *
 * [844] 比较含退格的字符串
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
  bool backspaceCompare(string s, string t) {
    return resetStr(s) == resetStr(t);
  }

  std::stack<char> resetStr(string s) {
    std::stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '#')
        st.push(s[i]);
      else if (!st.empty())
        st.pop();
    }
    return st;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */

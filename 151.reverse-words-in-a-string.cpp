/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=
 *
 * [151] 反转字符串中的单词
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
  string reverseWords(string s) {
    std::list<std::string> words;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      }
      int j = i;
      while (j < s.size() && s[j] != ' ') {
        j++;
      }
      words.push_front(s.substr(i, j - i));
      i = j;
    }
    std::string res;
    for (auto& word : words) {
      res += word + " ";
    }
    return res.substr(0, res.size() - 1);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=345 lang=cpp
 * @lcpr version=
 *
 * [345] 反转字符串中的元音字母
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
  string reverseVowels(string s) {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                       'A', 'E', 'I', 'O', 'U'};
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
      while (l < r && !vowels.count(s[l])) l++;
      while (l < r && !vowels.count(s[r])) r--;
      if (l < r) swap(s[l++], s[r--]);
    }
    return s;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "hello"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

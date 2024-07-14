/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 * @lcpr version=
 *
 * [1456] 定长子串中元音的最大数目
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
  int maxVowels(string s, int k) {
    int left = 0, right = 0;
    int res = 0;
    int count = 0;
    while (right < s.size()) {
      if (isVowel(s[right])) {
        count++;
      }
      if (right - left + 1 == k) {
        res = max(res, count);
        if (isVowel(s[left])) {
          count--;
        }
        left++;
      }
      right++;
    }
    return res;
  }

  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
// @lc code=end

/*
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

// @lcpr case=start
// "rhythms"\n4\n
// @lcpr case=end

// @lcpr case=start
// "tryhard"\n4\n
// @lcpr case=end

 */

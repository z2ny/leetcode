/*
 * @lc app=leetcode.cn id=443 lang=cpp
 * @lcpr version=
 *
 * [443] 压缩字符串
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
  int compress(vector<char>& chars) {
    int i = 0, j = 0;
    while (i < chars.size()) {
      int count = 1;
      while (i < chars.size() - 1 && chars[i] == chars[i + 1]) {
        i++;
        count++;
      }
      chars[j] = chars[i];
      j++;
      if (count > 1) {
        // 如果组长度为 10 或 10 以上，则在 chars 数组中会被拆分为多个字符
        for (char c : std::to_string(count)) {
          chars[j] = c;
          j++;
        }
      }
      i++;
    }
    return j;
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["a","a","b","b","c","c","c"]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]\n
// @lcpr case=end

 */

int main() {
  std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  Solution().compress(chars);
  return 0;
}
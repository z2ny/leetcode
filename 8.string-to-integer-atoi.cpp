/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lcpr-template-start
using namespace std;
#include <math.h>

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
  int myAtoi(string s) {
    int res = 0;
    int flag = 1;
    int i = 0;
    while (i < s.size() && s[i] == ' ') i++;

    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
      flag = (s[i] == '+') ? 1 : -1;
      i++;
    }

    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
      if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
        return flag == 1 ? INT_MAX : INT_MIN;
      res = res * 10 + (s[i] - '0');
      i++;
    }
    // if (res * flag > INT_MAX) return INT_MAX;
    // if (res * flag < INT_MIN) return INT_MIN;
    // 不要后置判断，因为可能已经溢出 无法处理（leetcode假设最大只有32位的整形）
    return res * flag;
  }
};

// int main() {
//   Solution sol;
//   std::cout << sol.myAtoi("     -042") << std::endl;
//   return 0;
// }
// @lc code=end

/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */

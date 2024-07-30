/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=
 *
 * [394] 字符串解码
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
  string decodeString(string s) {
    stack<int> countStack;      // 用于存储重复次数的栈
    stack<string> resultStack;  // 用于存储中间结果的栈
    string currentString = "";  // 当前处理的字符串
    int i = 0;

    while (i < s.size()) {
      if (isdigit(s[i])) {
        int num = 0;
        // 解析完整的数字并压入 countStack
        while (isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        countStack.push(num);
      } else if (s[i] == '[') {
        // 将当前字符串压入 resultStack 并开始新的字符串
        resultStack.push(currentString);
        currentString = "";
        i++;
      } else if (s[i] == ']') {
        // 从 resultStack 弹出字符串并根据 countStack 重复它
        string temp = resultStack.top();
        resultStack.pop();
        int repeatTimes = countStack.top();
        countStack.pop();

        for (int j = 0; j < repeatTimes; j++) {
          temp += currentString;
        }

        currentString = temp;
        i++;
      } else {
        // 收集字母到 currentString 中
        currentString += s[i];
        i++;
      }
    }

    return currentString;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

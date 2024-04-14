#
# @lc app=leetcode.cn id=151 lang=python3
#
# [151] 反转字符串中的单词
#


# @lc code=start
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        for i in range(len(words) // 2):
            # temp = words[i]
            # words[i] = words[len(words)-i-1]
            # words[len(words)-i-1] = temp
            words[i], words[len(words) - i - 1] = words[len(words) - i - 1], words[i]
        return " ".join(words)


# @lc code=end

#
# @lc app=leetcode.cn id=344 lang=python3
#
# [344] 反转字符串
#


# @lc code=start
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l = len(s)
        # 注意range的范围，以及len的范围
        for i in range(len(s)//2):
            temp = s[i]
            s[i] = s[l-1-i]
            s[l-1-i] = temp

# @lc code=end

#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#


# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        # 为什么要从中间向两边扩散呢，还要判奇偶，由外向内不好吗
        str_x = str(x)
        left = 0
        right = len(str_x) - 1
        while left <right:
            if str_x[left] != str_x[right]:
                return False
            left = left+1
            right = right -1
        return True


# @lc code=end

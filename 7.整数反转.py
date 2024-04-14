#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#


# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            res = -self.reverse(-x)
        else:
            res = 0
            length = len(str(x))
            for i in range(length):
                temp = x % 10
                res += temp * 10 ** (length -1 - i)
                x = x // 10
        return res if res.bit_length() < 32 else 0


# @lc code=end

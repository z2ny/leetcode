#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#


# @lc code=start
class Solution:
    def isUgly(self, n: int) -> bool:
        # 注意边界，要加0的情况否则会死循环
        if n <= 0:
            return False
        while n % 2 == 0:
            n /= 2
        while n % 3 == 0:
            n /= 3
        while n % 5 == 0:
            n /= 5
        return n == 1


# @lc code=end

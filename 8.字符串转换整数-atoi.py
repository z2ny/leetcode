#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

import re
# @lc code=start
class Solution:
    def myAtoi(self, s: str) -> int:
        return max(
            min(int(*re.findall("^[\+\-]?\d+", s.lstrip())), 2**31 - 1), -(2**31)
        )

        # *号是python的解包操作符，可以将序列解包成一个个单独的元素，这里是将列表解包成一个个字符串，然后转换成整数
        # 例如很多function的参数是可变参数，就是用*号来解包的，fuc(*args)，输入的时候只需要输入一个列表，就可以将列表中的元素解包成一个个单独的元素，然后传入函数中

        # max(min(num,INT_MAX),INT_MIN)


# @lc code=end

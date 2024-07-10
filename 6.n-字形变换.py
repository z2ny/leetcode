#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] N 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        # res表示每行的字符串
        res = [''] * numRows
        i, flag = 0, -1
        # 不需要管中间的空格，只需要输出的字符串是对的就行
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1:
                flag = -flag
            i += flag
        return ''.join(res)
# @lc code=end


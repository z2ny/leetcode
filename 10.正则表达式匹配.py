#
# @lc app=leetcode.cn id=10 lang=python3
#
# [10] 正则表达式匹配
#
import re
# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # match:从字符串第一个字符开始匹配，如果满足pattern则返回一个Match对象，有group()被匹配的字符串,start()匹配开始的位置,end()结束的位置,span()开始结束位置的元组
        # search：不用从第一个字符开始，找到整个s中第一个符合pattern的子字符串，同样返回一个Match对象
        # findall，返回所有符合的子字符串构成的list
        return True if s in re.findall(p,s) else False
# @lc code=end


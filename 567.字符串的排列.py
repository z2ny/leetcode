#
# @lc app=leetcode.cn id=567 lang=python3
#
# [567] 字符串的排列
#


# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import defaultdict

        need, window = defaultdict(int), defaultdict(int)
        for c in s1:
            need[c] += 1
        left, right, valid = 0, 0, 0
        while right < len(s2):
            c = s2[right]
            right += 1
            # 注意这里是if，如果c不是目标字符就跳过，并且，如果此时长度已经超过了s1，就增加left以缩小长度
            # 直到碰到第一个目标字符，此时left和right一定只隔一个s1长度
            if c in need:
                window[c] += 1
                if window[c] == need[c]:
                    valid += 1
            while right - left >= len(s1):
                if valid == len(need):
                    return True
                d = s2[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1

        return False


# @lc code=end

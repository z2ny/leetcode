#
# @lc app=leetcode.cn id=76 lang=python3
#
# [76] 最小覆盖子串
#


# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # dict在get(key)时若key不存在会报错，而defaultdict可以设置返回默认值
        from collections import defaultdict

        # 滑动窗口，先增大right找一个可行解，再缩小left直到不够满足，并再次增大right继续找可行解，直到right到末尾
        need, window = defaultdict(int), defaultdict(int)
        for c in t:
            need[c] += 1
        left, right, valid = 0, 0, 0
        # float('inf')表正无穷
        start, length = 0, float("inf")

        while right < len(s):
            c = s[right]
            right += 1
            if c in need:
                window[c] += 1
                # 只有同一个字符的数量匹配了，才把valid+1
                if window[c] == need[c]:
                    valid += 1
            while valid == len(need):
                if right - left < length:
                    start = left
                    length = right - left
                d = s[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1

        return "" if length == float("inf") else s[start : start + length]


# @lc code=end

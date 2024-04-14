#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import defaultdict

        need, window = defaultdict(int), defaultdict(int)
        res = []
        left, right, valid = 0, 0, 0
        for c in p:
            need[c] += 1

        while right < len(s):
            c = s[right]
            right += 1
            if c in need:
                window[c] += 1
                if window[c] == need[c]:
                    valid += 1
            while right - left >= len(p):
                if valid == len(need):
                    res.append(left)
                d = s[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1
        return res


# @lc code=end

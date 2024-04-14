#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#


# @lc code=start


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # keys = set()
        # # 滑动窗口
        # left = right = 0
        # max_len = 0
        # while left < len(s):
        #     while right < len(s) and s[right] not in keys:
        #         keys.add(s[right])
        #         right = right + 1
        #     max_len = max(max_len, right - left)
        #     # 这里不需要把集合清空了再重新做，只需要把左边的重复字符去掉，左值针向右移动一个，继续上述步骤即可
        #     keys.remove(s[left])
        #     left = left + 1
        # return max_len
        from collections import defaultdict
        window = defaultdict(int)
        left, right, max_len = 0, 0, 0
        while right <len(s):
            c = s[right]
            right +=1
            window[c] +=1
            # 碰到第一个重复字符，开始缩小窗口
            while window[c] >1:
                d = s[left]
                left +=1
                window[d]-=1
            max_len = max(max_len,right -left)

        return max_len


# @lc code=end

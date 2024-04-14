#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        min_len = min([len(s) for s in strs])
        for i in range(min_len):
            for j in range(1, len(strs)):
                if strs[j][i] != strs[j-1][i]:
                    return strs[0][:i]
        return strs[0][:min_len]
# @lc code=end


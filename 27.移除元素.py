#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        p = 0
        for q in range(len(nums)):
            if nums[q] != val:
                nums[p] = nums[q]
                p += 1
        return p
# @lc code=end


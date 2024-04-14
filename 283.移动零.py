#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

import numpy as np
# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p = 0
        for q in range(len(nums)):
            if nums[q] != 0:
                nums[p] = nums[q]
                p = p + 1

        for i in range(p,len(nums)):
            nums[i] = 0

        # 下面的意思是将数组的值赋给i，但是修改i并不能改变实际数组值
        # for i in nums[p:]:
        #     i = 0

# @lc code=end

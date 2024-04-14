#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除有序数组中的重复项
#


# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # if l == 1:
        #     return 1
        # 从下标为1的元素开始工作，如果q与前一个元素相同，就一直往后移
        # p = q = 1
        # while q < len(nums):
        #     if nums[q] == nums[q - 1]:
        #         q += 1
        #     else:
        #         nums[p] = nums[q]
        #         p += 1
        #         q += 1
        # return p
        p = 1
        for q in range(1, len(nums)):
            if nums[q] != nums[q - 1]:
                nums[p] = nums[q]
                p += 1
        return p


# @lc code=end

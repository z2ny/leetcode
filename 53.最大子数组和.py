#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#


# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 3种可能，要么子序列完全在左半边，要么完全在右半边，要么横跨中间
        n = len(nums)
        # 终止条件
        if n == 1:
            return nums[0]
        else:
            # 递归将问题分解为左右两个半边的找子序列问题
            max_left = self.maxSubArray(nums[0 : len(nums) // 2])
            max_right = self.maxSubArray(nums[len(nums) // 2 : len(nums)])

        # 问题分解后，就可以直接从左到右或从右到左算最大值
        # 左侧边界
        max_l = nums[len(nums) // 2 - 1]
        tmp = 0
        for i in range(len(nums) // 2 - 1, -1, -1):
            tmp += nums[i]
            max_l = max(tmp, max_l)
        # 右侧边界
        max_r = nums[len(nums) // 2]
        tmp = 0
        for i in range(len(nums) // 2, len(nums)):
            tmp += nums[i]
            max_r = max(tmp, max_r)
        # 返回三个中的最大值
        return max(max_right, max_left, max_l + max_r)


# @lc code=end

#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#


# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            else:
                # 收缩right，逼近左边界，等循环结束left=right时，一定是左边界
                right = mid
        left_bound = left

        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid
            else:
                # 收缩left，逼近右边界，但是注意由于是左闭右开区间，最后left=right时得到的结果需要减1
                left = mid + 1
        right_bound = left - 1

        # 如果数组里没有该元素，也就是上述的else都不成立
        # 如搜索6，最后一步可能是left指向5，right指向7，然后left+1 =right结束循环，此时都指向7
        # 此时left_bound和right_bound需要进一步判断
        return [left_bound, right_bound] if left_bound <=right_bound else [-1,-1]


# @lc code=end

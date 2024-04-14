#
# @lc app=leetcode.cn id=167 lang=python3
#
# [167] 两数之和 II - 输入有序数组
#


# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = len(numbers)
        left, right = 0, l - 1
        while left < right:
            gap = numbers[left] + numbers[right] - target
            if gap > 0:
                right -= 1
            if gap < 0:
                left += 1
            if gap == 0:
                return [left + 1, right + 1]


# @lc code=end

#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#


# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # left, right = 0, len(nums) - 1
        # # 这里的left和right为闭区间，即right指向的元素也在搜索空间中
        # # 所以终止条件就是当搜索空间为空时
        # # 当left=right时，搜索空间还有唯一的一个元素，所以还要继续循环，所以下面的while中是小于等于
        # # 这种处理方式能找target，但是无法找到target的左右侧边界，如1，2，2，2，3，只能找到中间那个2
        # while left <= right:
        #     mid = (left + right) // 2
        #     if nums[mid] < target:
        #         left = mid + 1
        #     elif nums[mid] > target:
        #         right = mid - 1
        #     else:
        #         return mid
        # return -1

        left ,right = 0,len(nums)
        while left<right:
            mid = (left+right)//2
            if nums[mid]<target:
                left  = mid +1
            elif nums[mid]>target:
                right = mid
            else:
                return mid
        return -1

# @lc code=end

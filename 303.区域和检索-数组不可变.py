#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#


# @lc code=start
class NumArray:
    def __init__(self, nums: List[int]):
        # presum是当前元素以及之前所有元素的和，初始化时presum[0] = nums[0]
        self.presum = [nums[0]] * len(nums)
        for i in range(1, len(nums)):
            self.presum[i] = nums[i] + self.presum[i - 1]

    def sumRange(self, left: int, right: int) -> int:
        # 题目意思是给定一个数组，会多次计算其中某一段的元素和，因此这个多次会频繁调用sumRange中的for循环，导致效率不高
        # 更高效的做法是使用前缀和数组，计算每个元素及其之前的累加和

        # res = 0
        # for i in range(left,right+1):
        #     res = res + self.nums[i]
        # return res
        if left == 0:
            return self.presum[right]
        return self.presum[right] - self.presum[left - 1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
# @lc code=end

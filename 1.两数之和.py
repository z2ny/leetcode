#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#
# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 数组里每个数求差，在遍历找这个数
        # # 直接 for in 的话，get不到数组下标
        # for i in range(len(nums)):
        #     gap = target - nums[i]
        #     # 从i+1开始遍历，免得出现i=j重复下标
        #     for j in range(i+1,len(nums)):
        #         if gap == nums[j]:
        #             return [i,j]

        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []
        # 基本思路通过一次枚举，边建字典边判断需要的数在不在这个字典里面
        # 建的字典中，索引是数组值，而对应的值是要的数组下标，每次枚举判断target-num的差值在不在字典的索引里，如果有直接返回即可


# @lc code=end

#
# @lc app=leetcode.cn id=380 lang=python3
#
# [380] O(1) 时间插入、删除和获取随机元素
#


# @lc code=start
import random


class RandomizedSet:
    def __init__(self):
        self.nums = []
        # 记录每个元素对应在 nums 中的数组下标
        self.val_index = dict()

    def insert(self, val: int) -> bool:
        # 若 val 已存在，不用再插入
        if val in self.val_index:
            return False
        # 若 val 不存在，插入到 nums 尾部，
        # 并记录 val 对应的数组下标
        self.val_index[val] = len(self.nums)
        self.nums.append(val)
        return True

    def remove(self, val: int) -> bool:
        # 若 val 不存在，不用再删除
        if val not in self.val_index:
            return False
        # 本质是将该元素与数组最后一个元素交换，再pop

        # 先删除字典中的索引
        index = self.val_index[val]
        del self.val_index[val]

        # 同时要把这个索引赋给数组最后一个元素，因为这个元素是要被移动到删除元素的位置的
        self.val_index[self.nums[-1]] = index
        # 交换 val 和最后一个元素
        self.nums[index], self.nums[-1] = self.nums[-1], self.nums[index]
        self.nums.pop()
        return True

    def getRandom(self) -> int:
        # 随机获取 nums 中的一个元素
        return random.choice(self.nums)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end

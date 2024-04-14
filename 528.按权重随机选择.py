#
# @lc app=leetcode.cn id=528 lang=python3
#
# [528] 按权重随机选择
#

# import bisect
from itertools import accumulate
import random


# @lc code=start
class Solution:
    def __init__(self, w: List[int]):
        # self.pre = list(accumulate(w))
        self.w = w
        self.len = len(w)
        self.total = sum(w)

    def pickIndex(self) -> int:
        # randint包含上下限，randrange不包含上限
        # 注意这里x不能取0，因为w中每个数就都有正的权值，每个index对应在total里面都是左开右闭(]，x共有1到self.total共total种可能
        x = random.randint(1, self.total)
        # return bisect.bisect_left(self.pre, x)
        res, step = 0, 0
        while res < self.len:
            step += self.w[res]
            if step >= x:
                return res
            res += 1


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
# @lc code=end

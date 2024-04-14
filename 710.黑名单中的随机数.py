#
# @lc app=leetcode.cn id=710 lang=python3
#
# [710] 黑名单中的随机数
#
import random


# @lc code=start
class Solution:
    def __init__(self, n: int, blacklist: List[int]):
        self.valid_num = n - len(blacklist)
        # 只在0到validnum-1上随机一个数，如果这个数命中了黑名单，就返回这个黑名单映射的有效数
        # 超过validnum范围的,需要被映射的数
        need = []
        for x in range(self.valid_num, n):
            if x not in blacklist:
                need.append(x)

        # 黑名单中，在validnum范围内的数
        black = []
        for b in blacklist:
            if b < self.valid_num:
                black.append(b)
        self.black_dict = dict(zip(black, need))

    def pick(self) -> int:
        x = random.randint(0, self.valid_num - 1)

        return x if x not in self.black_dict else self.black_dict[x]
  

# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()
# @lc code=end

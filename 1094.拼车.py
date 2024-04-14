#
# @lc app=leetcode.cn id=1094 lang=python3
#
# [1094] 拼车
#


# @lc code=start
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        temp = 0
        # diff[n] 表示在第n站需要上下车的人数
        diff = [0] * 1001
        for i in trips:
            diff[i[1]] = diff[i[1]] + i[0]
            diff[i[2]] = diff[i[2]] - i[0]
        for j in diff:
            temp = temp + j
            if temp > capacity:
                return False
        return True


# @lc code=end

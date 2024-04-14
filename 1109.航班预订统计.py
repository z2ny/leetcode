#
# @lc app=leetcode.cn id=1109 lang=python3
#
# [1109] 航班预订统计
#


# @lc code=start
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        temp = 0
        res = []
        diff = [0] * (n + 2)
        for i in bookings:
            diff[i[0]] = diff[i[0]] + i[2]
            diff[i[1]+1] = diff[i[1]+1] - i[2]
        for j in diff:
            temp = temp + j
            res.append(temp)
        return res[1:-1]


# @lc code=end

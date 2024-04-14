#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#


# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        up_bound = 0
        down_bound = n - 1
        left_bound = 0
        right_bound = n - 1

        flag = 1
        # 注意要初始化成二维数组
        res = [[0 for _ in range(n)] for _ in range(n)]
        while flag <= n * n:
            if up_bound <= down_bound:
                for i in range(left_bound, right_bound + 1):
                    res[up_bound][i] = flag
                    flag += 1
                up_bound += 1

            if right_bound >= left_bound:
                for i in range(up_bound, down_bound + 1):
                    res[i][right_bound] = flag
                    flag += 1
                right_bound -= 1

            if up_bound <= down_bound:
                for i in range(right_bound, left_bound - 1, -1):
                    res[down_bound][i] = flag
                    flag += 1
                down_bound -= 1

            if left_bound <= right_bound:
                for i in range(down_bound, up_bound - 1, -1):
                    res[i][left_bound] = flag
                    flag += 1
                left_bound += 1

        return res


# @lc code=end

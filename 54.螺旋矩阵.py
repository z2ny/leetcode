#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#


# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        up_bound = 0
        down_bound = len(matrix) - 1
        left_bound = 0
        right_bound = len(matrix[0]) - 1
        res = []
        while len(res) < len(matrix) * len(matrix[0]):
            if up_bound <= down_bound:
                for i in range(left_bound, right_bound + 1):
                    res.append(matrix[up_bound][i])
                up_bound += 1

            if left_bound <= right_bound:
                for i in range(up_bound, down_bound + 1):
                    res.append(matrix[i][right_bound])
                right_bound -= 1

            if up_bound <= down_bound:
                for i in range(right_bound, left_bound - 1, -1):
                    res.append(matrix[down_bound][i])
                down_bound -= 1

            if left_bound <= right_bound:
                for i in range(down_bound, up_bound - 1, -1):
                    res.append(matrix[i][left_bound])
                left_bound += 1

        return res


# @lc code=end

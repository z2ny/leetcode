#
# @lc app=leetcode.cn id=304 lang=python3
#
# [304] 二维区域和检索 - 矩阵不可变
#


# @lc code=start
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        h, l = len(matrix), len(matrix[0])
        # 这里的presum和上一题不一样，不包括本身
        self.preSum = [[0 for _ in range(l + 1)] for _ in range(h + 1)]
        for i in range(1,h + 1):
            for j in range(1,l + 1):
                self.preSum[i][j] = (
                    self.preSum[i - 1][j]
                    + self.preSum[i][j - 1]
                    + matrix[i - 1][j - 1]
                    - self.preSum[i - 1][j - 1]
                )

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.preSum[row2 + 1][col2 + 1]
            - self.preSum[row1][col2 + 1]
            - self.preSum[row2 + 1][col1]
            + self.preSum[row1][col1]
        )


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
# @lc code=end

#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#


# @lc code=start
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 先沿对角线做一次对称，即[x][y] = [y][x]，在对每个数组进行一次反转
        list_num = len(matrix)
        for i in range(list_num):
            for j in range(i, list_num):
                # temp = matrix[i][j]
                # matrix[i][j] = matrix[j][i]
                # matrix[j][i] = temp
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for array in matrix:
            for i in range(len(array) // 2):
                array[i], array[len(array) - 1 - i] = (
                    array[len(array) - 1 - i],
                    array[i],
                )


# @lc code=end

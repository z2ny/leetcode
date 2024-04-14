#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#


# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 穷举会超时
        # i = j = 0
        # max = 0
        # for i in range(0, len(height)):
        #     for j in range(i + 1, len(height)):
        #         if min(height[i], height[j]) * (j - i) > max:
        #             max = min(height[i], height[j]) * (j - i)
        # return max

        # 将i，j分置数组两侧
        # 如果移动长板，由于距离缩小，而且短板不变，所以乘积一定变小
        # 如果移动短板，虽然距离缩小，但短板可能增大，所以乘积可能变大
        # 因此只需要移动短板，记录最大值即可
        i, j = 0, len(height) - 1
        res = 0
        while i < j:
            # res = min(height[i], height[j]) * (j - i)
            if height[i] <= height[j]:
                temp = height[i] * (j - i)
                i = i + 1
            else:
                temp = height[j] * (j - i)
                j = j - 1
            res = temp if temp > res else res
        return res

# @lc code=end

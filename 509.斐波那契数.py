#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#


# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        # 暴力递归会导致递归溢出
        # if n == 1 or n == 2:
        #     return 1
        # return self.fib(n - 1) + self.fib(n - 2)

        memo = [0] * (n + 1)
        # 进行带备忘录的递归
        return self.dp(memo, n)

    # 带着备忘录进行递归
    def dp(self, memo: List[int], n: int) -> int:
        # base case
        if n == 0 or n == 1:
            return n
        # 已经计算过，不用再计算了
        if memo[n] != 0:
            return memo[n]
        memo[n] = self.dp(memo, n - 1) + self.dp(memo, n - 2)
        return memo[n]


# @lc code=end

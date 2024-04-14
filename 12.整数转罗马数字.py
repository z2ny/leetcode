#
# @lc app=leetcode.cn id=12 lang=python3
#
# [12] 整数转罗马数字
#


# @lc code=start
class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbol = {
            "M": 1000,
            "CM": 900,
            "D": 500,
            "CD": 400,
            "C": 100,
            "XC": 90,
            "L": 50,
            "XL": 40,
            "X": 10,
            "IX": 9,
            "V": 5,
            "IV": 4,
            "I": 1,
        }
        res = []
        # 每次先从M开始找最大的可以表示的符号，找到后将这一部分减去，继续
        for symbol, value in value_symbol.items():
            while num >= value:
                res.append(symbol)
                num = num - value

        # 将符合结果转化成字符串输出
        return ''.join(res)


# @lc code=end

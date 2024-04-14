#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#


# @lc code=start
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # 穷举
        # n = len(s)
        # # 记录出现过的子串
        # seen = set()
        # # 记录那些重复出现多次的子串
        # # 注意要用哈希集合，防止记录重复的结果
        # res = set()

        # for i in range(n - 9):
        #     subStr = s[i : i + 10]
        #     if subStr in seen:
        #         # 之前出现过，找到一个重复的
        #         res.add(subStr)
        #     else:
        #         # 之前没出现过，加入集合
        #         seen.add(subStr)
        # return list(res)

        # 如果使用滑动窗口：由于需要将窗口字符转为字符串并检查是否在集合中那个，复杂度仍然为O(NL),子字符串的对比需要消耗O(L)的复杂度
        # 关键在于不要将字符视作字符，而将其视为0123三个数字组成的10位4进制数，直接视为整形数字进行比较，就可以节省时间复杂度，由O(NL)变成O(N)
        # 但是当不是特定字符时，就需要256进制（ASCII）了，会导致哈希空间过大，此时需要取模，在判断是否有哈希冲突
        seen, res = set(),set()
        nums = [0] * len(s)
        for i in range(len(nums)):
            if s[i] == "A":
                nums[i] = 0
            elif s[i] == "G":
                nums[i] = 1
            elif s[i] == "C":
                nums[i] = 2
            elif s[i] == "T":
                nums[i] = 3

        L, R = 10, 4
        RL = R ** (L - 1)
        window_hash = 0
        left, right = 0, 0
        while right < len(nums):
            window_hash = R * window_hash + nums[right]
            right += 1
            if right - left == L:
                if window_hash in seen:
                    res.add(s[left:right])
                else:
                    seen.add(window_hash)
                window_hash -= nums[left] * RL
                left += 1
        return list(res)


# @lc code=end

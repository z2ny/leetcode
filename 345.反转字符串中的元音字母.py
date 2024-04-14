#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#


# @lc code=start
class Solution:
    def reverseVowels(self, s: str) -> str:
        target = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        x = []
        list_s = list(s)
        for i in range(len(s)):
            if s[i] in target:
                x.append(i)
        # x 存储元音字母在s中的下标
        l = len(x)
        # 字符串是不可变类型，不能直接赋值更改字符串的字符,所以加了个list_s
        for j in range(len(x) // 2):
            temp = s[x[j]]
            list_s[x[j]] = list_s[x[l - j - 1]]
            list_s[x[l - j - 1]] = temp
        return "".join(list_s)


# @lc code=end

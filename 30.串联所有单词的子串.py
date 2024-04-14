#
# @lc app=leetcode.cn id=30 lang=python3
#
# [30] 串联所有单词的子串


# @lc code=start
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        word_len = len(words[0])
        word_num = len(words)
        s_len = len(s)
        if s_len < word_len * word_num:
            return []
        words_dict = {}
        for word in words:
            if word not in words_dict:
                words_dict[word] = 1
            else:
                words_dict[word] += 1
        res = []
        for i in range(s_len - word_len * word_num + 1):
            temp_dict = {}
            j = 0
            while j < word_num:
                word = s[i + j * word_len : i + (j + 1) * word_len]
                if word not in words_dict:
                    break
                if word not in temp_dict:
                    temp_dict[word] = 1
                else:
                    temp_dict[word] += 1
                if temp_dict[word] > words_dict[word]:
                    break
                j += 1
            if j == word_num:
                res.append(i)
        return res


# @lc code=end

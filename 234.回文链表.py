#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self):
        self.p = []
        self.q = []

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head:
            return True
        self.p.append(head.val)
        self.isPalindrome(head.next)
        self.q.append(head.val)
        return self.p == self.q

# @lc code=end


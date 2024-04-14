#
# @lc app=leetcode.cn id=876 lang=python3
#
# [876] 链表的中间结点
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        p = q = dummy
        while p and q:
            p = p.next
            q = q.next
            # q比p走得更快，到了后面，有可能q在第一步之后就空了，得判断一下
            if q:
                q = q.next
        return p


# @lc code=end

#
# @lc app=leetcode.cn id=86 lang=python3
#
# [86] 分隔链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less_head = less_tail = ListNode(0)
        more_head = more_tail = ListNode(0)
        while head:
            if head.val < x:
                less_tail.next = ListNode(head.val)
                less_tail = less_tail.next
            else:
                more_tail.next = ListNode(head.val)
                more_tail = more_tail.next
            head = head.next
        less_tail.next = more_head.next
        return less_head.next


# @lc code=end

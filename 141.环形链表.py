#
# @lc app=leetcode.cn id=141 lang=python3
#
# [141] 环形链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        dummy = ListNode(0, head)
        p = q = dummy
        while p and q:
            p = p.next
            q = q.next
            # q比p走得快，所以后面可能q第一步之后就空了，得判断一下
            if q:
                q = q.next
            else:
                return False
            if p == q:
                return True
        # return False

# @lc code=end

#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # 递归反转链表前n个元素，并返回反转完毕的表头元素
    def reverseN(self, head: Optional[ListNode], n: int):
        if n == 1:
            return head
        last = self.reverseN(head.next, n - 1)
        head.next.next = head
        head.next = None
        return last

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None
        p = head

        # 走k步，有k个就可以反转，没有就返回这组的第一个元素
        for _ in range(k):
            if not p:
                return head
            p = p.next

        # newhead是反转后整个链表的表头元素
        new_head = self.reverseN(head, k)

        # 反转了一组后，递归反转剩余的链表，p刚好是剩余链表的表头元素
        head.next = self.reverseKGroup(p, k)

        # 从第一次反转过后，new_head就没变过，剩下的都是将p走k步，在递归的反转以p为头的子链表
        return new_head


# @lc code=end

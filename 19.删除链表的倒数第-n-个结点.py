#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # 不好找边界，可以先创个头节点
        dummy = ListNode(-1,head)
        # 让后一个指针从dummy开始，避免了一些边界问题，因为p不能指向要删除的节点，而是指向他前一个节点，才好删除
        p = dummy
        q = head
        for _ in range(n):
            q = q.next 
        while q:
            p = p.next
            q = q.next
        p.next = p.next.next
        # 不要返回head，因为首节点也有可能被删，返回头节点的next
        # return head
        return dummy.next

# @lc code=end

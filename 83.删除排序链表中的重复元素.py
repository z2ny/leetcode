#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # dummy = ListNode(0, head)
        # p = q = head
        # while q.next:
        #     if q.val != q.next.val:
        #         p.next = q.next
        #         p = p.next
        #     q = q.next
        # return dummy.next
        # # 上面的意思，每次遇到不重复的元素，才会把上一个重复的元素清理掉，因此遇到像11233这种最后的重复元素的，33无法清理

        cur = head
        while cur:
            while cur.next and cur.next.val == cur.val:
                cur.next = cur.next.next
            cur = cur.next
        return head


# @lc code=end

#
# @lc app=leetcode.cn id=206 lang=python3
#
# [206] 反转链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 递归：输入头节点head，将以head为起点的链表反转，再返回反转后的第一个节点
        if not head or not head.next:
            return head
        last = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return last
        # dummy = ListNode()
        # p = head
        # while p:
        #     # 头插法
        #     # 这里不能直接用temp = p，而要创建一个值为p.val的全新节点
        #     temp = ListNode(p.val)
        #     temp.next = dummy.next
        #     dummy.next = temp
        #     p = p.next
        # return dummy.next


# @lc code=end

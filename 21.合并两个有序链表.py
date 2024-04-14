#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # # 加入一个值为0的头节点，头节点在需要创建新链表时可以简化边界处理
        # p = q = ListNode(0)
        # while list1 and list2:
        #     if list1.val <= list2.val:
        #         q.next = ListNode(list1.val)
        #         q = q.next
        #         list1 = list1.next
        #     else:
        #         q.next = ListNode(list2.val)
        #         q = q.next
        #         list2 = list2.next
        # if list1:
        #     q.next = list1
        # if list2:
        #     q.next = list2
        # return p.next
        dummy = ListNode(-1)
        p = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                p.next = list1
                p = p.next
                list1 = list1.next
            else:
                p.next = list2
                p =p.next
                list2 = list2.next
        if list1:
            p.next = list1
        else:
            p.next = list2
        return dummy.next


# @lc code=end

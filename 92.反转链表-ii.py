#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        p = dummy
        for _ in range(left - 1):
            p = p.next
        q = p.next
        p.next = None
        # p是待反转链表的前一个节点，q是第一个待反转的节点
        # 将p截断，头插法反转
        len = right - left + 1
        tail = p
        for _ in range(len):
            temp = ListNode(q.val)
            temp.next = p.next
            p.next = temp
            q = q.next
            # 下面这个语句只会在第一次头插时执行一次，这样tail就始终是头插法中的末尾节点了
            tail = tail.next if tail.next else tail
        # 结束循环时q会指向right后面不用反转的链表
        tail.next = q
        return dummy.next


# @lc code=end

#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # 直接按位相加，搞个进位位，注意长度不一致，短的用完后补0
        add = 0
        # 单链表,需要设一个头指针,要不然怎么返回结果
        result = temp = ListNode(None)
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            sum = (x + y + add) % 10
            add = (x + y + add) // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            # temp.val = sum
            # temp = temp.next
            # 这里不能直接next到下一个，因为next的节点还没创建呢
            # 每次在链表后面创一个新的节点再写数，而不能写当前节点再指向下一个节点
            temp.next = ListNode(sum)
            temp = temp.next
        if add:
            temp.next = ListNode(add)
        return result.next
# @lc code=end


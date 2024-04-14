#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        # 让两个指针分别A，B的头节点开始遍历，同时遍历完自己的链表后开始遍历对方的，这样总长度相同，在遍历对方的链表时可以同时到达交点
        p, q = headA, headB

        while p != q:
            # 如果不相交，这样会保证p和q遍历完A+B后同时为None，结束循环
            # p = p.next
            # if not p:
            #     p = headB
            # q = q.next
            # if not q:
            #     q = headA
            # 这样写 让p到末尾后直接跳到了headB，没有给两个指针为空的机会
            if not p:
                p = headB
            else:
                p = p.next
            if not q:
                q = headA
            else:
                q = q.next
        return p


# @lc code=end

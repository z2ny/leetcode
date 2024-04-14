#
# @lc app=leetcode.cn id=142 lang=python3
#
# [142] 环形链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 当快指针和慢指针相遇时，快比慢多走一圈。慢走了k步，快走了2k步，而他们的差k就是这个环的长度
        # 此时假设据环的起点为m，即头节点到起点的距离为m。那么两个指针到起点的距离刚好是k-(k-m)=m
        dummy = ListNode(0, head)
        p = q = r = dummy
        while p and q:
            p = p.next
            q = q.next
            # q比p走得快，所以后面可能q第一步之后就空了，得判断一下
            if q:
                q = q.next
            else:
                return None
            if p == q:
                break
        # 还有一种可能：q自然的走到了表尾，此时跳出while，但是也需要返回
        if not q:
            return None
        while p != r:
            p = p.next
            r = r.next
        return r


# @lc code=end

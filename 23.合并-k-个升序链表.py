#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并 K 个升序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return
        dummy = ListNode(-1)
        p = dummy
        heap = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i))
        # for list in lists:
        #     if list:
        #         heapq.heappush(heap, (list.val,list))
        # 这里有问题，元组压进堆后，heapq会从第一个元素开始比较，但list作为自定义类无法进行比较
        while heap:
            rear_val, i = heapq.heappop(heap)
            p.next = ListNode(rear_val)
            lists[i] = lists[i].next
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i))
            p = p.next
        return dummy.next


# @lc code=end

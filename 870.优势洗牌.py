#
# @lc app=leetcode.cn id=870 lang=python3
#
# [870] 优势洗牌
#

import heapq


# @lc code=start
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # heap = []
        # # 建一个nums2的大根堆，默认为小根堆，所以取负
        # for i in range(0, len(nums2)):
        #     heapq.heappush(heap, (-nums2[i], i))、
        maxpq = [(-val, i) for i, val in enumerate(nums2)]
        heapq.heapify(maxpq)
        res = [0] * len(nums1)
        # sort默认升序排列，left指向最小值，right指向最大值
        nums1.sort()
        left, right = 0, len(nums1) - 1
        while left <= right:
            val, idx = heapq.heappop(maxpq)
            if nums1[right] > -val:
                res[idx] = nums1[right]
                right -= 1
            else:
                res[idx] = nums1[left]
                left += 1
        return res


# @lc code=end

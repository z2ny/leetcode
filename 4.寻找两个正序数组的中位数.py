#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#


# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # # 使用归并排序，还可以用二分搜索简化
        # total = []
        # while nums1 and nums2:
        #     if nums1[0] <= nums2[0]:
        #         total.append(nums1[0])
        #         nums1.pop(0)
        #     else:
        #         total.append(nums2[0])
        #         nums2.pop(0)
        # if nums1:
        #     total.extend(nums1)
        # elif nums2:
        #     total.extend(nums2)
        # if len(total) % 2 == 1:
        #     return total[len(total) // 2]
        # else:
        #     return (total[len(total) // 2] + total[len(total) // 2 - 1]) / 2

        # 先确定其中一个数组分割线的位置，这样，由于中位数两边元素的个数是相等的，就可以得出另外一个数组分割线的位置
        # 分割线确定之后，再看所有左边的元素是否<=右边的元素，用来判断这个分割线是不是我们需要的中位数分割线
        # 总个数为奇数时，不妨令左边个数比右边多一个，这样中位数就是左边最大的那一个，这样左边个数为(m+n+1)/2，右边为(m+n)/2 （int型向下取整）
        # 总个数为偶数时，左右两边的个数均为(m+n)/2，由向下取整的特性，左边也是(m+n+1)/2，这样就统一了、
        # 确保nums1为短数组，nums2为长数组
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        inf = 2**40
        l1, l2 = len(nums1), len(nums2)
        # 一开始nums1左边0个元素，右边l1个元素
        left, right = 0, l1
        mean1, mean2 = 0, 0
        while left <= right:
            # i是定义的nums1的分割线右边元素下标，j是对应的nums2的分割线右边元素下标
            # 这里使用二分查找
            i = (left + right) // 2
            j = (l1 + l2 + 1) // 2 - i

            # 如果分割线左边没有元素了，用-inf替代，不影响找左边的最大值，右边没元素了用inf替代，不影响找右边最小值
            nums_il = -inf if i == 0 else nums1[i - 1]
            nums_ir = inf if i == l1 else nums1[i]
            nums_jl = -inf if j == 0 else nums2[j - 1]
            nums_jr = inf if j == l2 else nums2[j]

            # 需要满足il<=jr and jl<=ir，才算找到中位数
            # 但实际上，以上条件等价于：找到最大的il<=jr。因为il是最大的可满足il<=jr的了，此时的ir就肯定>=jr,即ir>jl
            if nums_il <= nums_jr:
                mean1, mean2 = max(nums_il, nums_jl), min(nums_ir, nums_jr)
                # 进行二分搜索，以逼近最大的il
                left = i + 1
            else:
                right = i - 1
        return (mean1 + mean2) / 2 if (l1 + l2) % 2 == 0 else mean1


# @lc code=end

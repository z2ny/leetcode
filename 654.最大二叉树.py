#
# @lc app=leetcode.cn id=654 lang=python3
#
# [654] 最大二叉树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return
        max_val = max(nums)
        root = TreeNode(max_val)
        root.left = self.constructMaximumBinaryTree(nums[0 : nums.index(max_val)])
        root.right = self.constructMaximumBinaryTree(nums[nums.index(max_val) + 1 :])
        return root


# @lc code=end

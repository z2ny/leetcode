#
# @lc app=leetcode.cn id=104 lang=python3
#
# [104] 二叉树的最大深度
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self) -> None:
        self.maxd = 0
        self.depth = 0

    def traverse(self, root: Optional[TreeNode]):
        if not root:
            return
        self.depth += 1
        if not root.left and not root.right:
            self.maxd = max(self.maxd, self.depth)
        self.traverse(root.left)
        self.traverse(root.right)
        self.depth -= 1

    def maxDepth(self, root: Optional[TreeNode]):
        self.traverse(root)
        return self.maxd


# @lc code=end

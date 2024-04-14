#
# @lc app=leetcode.cn id=543 lang=python3
#
# [543] 二叉树的直径
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        # 记录最大直径的长度
        self.maxl = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # 就是节点左右子树最大深度之和
        self.maxDepth(root)
        return self.maxl

    def maxDepth(self, root: Optional[TreeNode]):
        if not root:
            return 0
        leftmax = self.maxDepth(root.left)
        rightmax = self.maxDepth(root.right)
        temp = leftmax + rightmax
        self.maxl = max(temp, self.maxl)
        return 1 + max(leftmax, rightmax)


# @lc code=end

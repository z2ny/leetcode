#
# @lc app=leetcode.cn id=106 lang=python3
#
# [106] 从中序与后序遍历序列构造二叉树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder:
            return
        root_val = postorder[-1]
        root = TreeNode(root_val)

        left_len = inorder.index(root_val)

        root.left = self.buildTree(inorder[:left_len], postorder[:left_len])
        root.right = self.buildTree(inorder[left_len + 1 :], postorder[left_len:-1])
        return root


# @lc code=end

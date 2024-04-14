#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return

        # preorder中第一个肯定是当前的root
        # 根据当前root在inorder中的位置得出左右子树的长度
        root_val = preorder[0]
        root = TreeNode(root_val)

        # root在inorder中的位置，同时也只做子树的长度
        left_len = inorder.index(root_val)

        root.left = self.buildTree(preorder[1 : left_len + 1], inorder[:left_len])
        root.right = self.buildTree(preorder[left_len + 1 :], inorder[left_len + 1 :])

        return root


# @lc code=end

#
# @lc app=leetcode.cn id=226 lang=python3
#
# [226] 翻转二叉树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.traverse(root)
        return root

    def traverse(self, root):
        if not root:
            return
        # 移到中序或后序也可以，但是中序的话，就得继续traverse left，因为已经交换了
        # root.left, root.right = root.right, root.left
        self.traverse(root.left)
        root.left, root.right = root.right, root.left
        self.traverse(root.left)


# @lc code=end

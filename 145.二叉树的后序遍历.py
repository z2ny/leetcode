#
# @lc app=leetcode.cn id=145 lang=python3
#
# [145] 二叉树的后序遍历
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
        self.res = []

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.traverse(root)
        return self.res

    def traverse(self, root):
        if not root:
            return
        self.traverse(root.left)
        self.traverse(root.right)
        self.res.append(root.val)


# @lc code=end

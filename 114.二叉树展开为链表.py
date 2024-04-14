#
# @lc app=leetcode.cn id=114 lang=python3
#
# [114] 二叉树展开为链表
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return

        self.flatten(root.left)
        self.flatten(root.right)
        # 在后序位置，可以认为所有子树都已经完成了对应操作，只需要看这一步该怎么做就好
        # 左右子树都已经被拉平，接下来把右子树接到左子树上面，在把左子树变成右子树即可
        left_l = root.left
        right_l = root.right
        root.right = left_l
        root.left = None

        # while left_l.right:
        #     left_l =left_l.rght
        # left_l.right = right_l

        while root.right:
            root = root.right
        root.right = right_l

# @lc code=end


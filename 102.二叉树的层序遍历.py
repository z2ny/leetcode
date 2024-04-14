#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        res = []
        p = [root]
        while p:
            layer = []
            # 每一层，组成数组，并加入下一层的节点进队列
            for _ in range(len(p)):
                temp = p.pop(0)
                layer.append(temp.val)
                if temp.left:
                    p.append(temp.left)
                if temp.right:
                    p.append(temp.right)
            res.append(layer)
        return res
# @lc code=end

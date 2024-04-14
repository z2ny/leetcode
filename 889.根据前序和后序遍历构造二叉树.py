#
# @lc app=leetcode.cn id=889 lang=python3
#
# [889] 根据前序和后序遍历构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import random


class Solution:
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        if not preorder:
            return
        root_val = preorder[0]
        root = TreeNode(root_val)

        # 这里不能随机，因为随机出的长度，先序和后序序列可能无法满足
        # 虽然先后序不能确定一棵树，但是也不是所有树都能满足这个先后序
        # left_len = random.randint(0, len(preorder) - 1)
        if len(preorder) == 1:
            return root

        # preorder[1]是左子树的根节点
        # 如果没有左子树，只有右子树也不要紧，他会把原本右子树的size当作左子树的长度继续算，实际上，这样子生成的也是可以满足前后序的
        # 试想一下，如果根节点只有一个子树，那么这棵子树在左还是在右，他的前序都是根->子树，后序也都是子树->根
        # 而这个代码只是默认在只有一个子树的时候，子树放在左边罢了

        left_len = postorder.index(preorder[1]) + 1

        root.left = self.constructFromPrePost(
            preorder[1 : left_len + 1], postorder[:left_len]
        )
        root.right = self.constructFromPrePost(
            preorder[left_len + 1 :], postorder[left_len:-1]
        )
        return root


# @lc code=end

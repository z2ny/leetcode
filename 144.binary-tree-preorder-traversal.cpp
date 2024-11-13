/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=
 *
 * [144] 二叉树的前序遍历
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> res;
    if (!root)
      return res;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *temp = st.top();
      res.push_back(temp->val);
      st.pop();
      if (temp->right)
        st.push(temp->right);
      if (temp->left)
        st.push(temp->left);
    }
    return res;
  }

  // vector<int> preorderTraversal(TreeNode * root)
  // {
  //   vector<int> res;
  //   preorder(root, res);
  //   return res;
  // }

  // void preorder(TreeNode * root, vector<int> & res)
  // {
  //   if (root == nullptr)
  //     return;
  //   res.push_back(root->val);
  //   preorder(root->left, res);
  //   preorder(root->right, res);
  // }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

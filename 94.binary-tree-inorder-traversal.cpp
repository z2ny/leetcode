/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=
 *
 * [94] 二叉树的中序遍历
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
  vector<int> inorderTravesal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> res;
    if (!root)
      return res;
    st.push(root);
    TreeNode *cur = root;
    while (!st.empty())
    {
      
    }
  }

  void pushLeft(TreeNode *cur, stack<TreeNode *> st)
  {
    while (cur)
    {
      st.push(cur);
      cur = cur->left;
    }
  }

  // vector<int> inorderTraversal(TreeNode* root) {
  //   vector<int> res;
  //   inorder(root, res);
  //   return res;
  // }

  // void inorder(TreeNode* cur, vector<int>& res) {
  //   if (!cur) return;
  //   inorder(cur->left, res);
  //   res.push_back(cur->val);
  //   inorder(cur->right, res);
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

 */

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=
 *
 * [2] 两数相加
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add = 0;
    ListNode* res = new ListNode(0);
    ListNode* temp = res;
    while (l1 != nullptr || l2 != nullptr) {
      int x = l1 == nullptr ? 0 : l1->val;
      int y = l2 == nullptr ? 0 : l2->val;
      int sum = x + y + add;
      add = sum / 10;
      temp->next = new ListNode(sum % 10);
      temp = temp->next;
      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
    }
    if(add ==1) temp->next = new ListNode(1);
    return res->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

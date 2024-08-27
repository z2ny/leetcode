/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 * @lcpr version=
 *
 * [2130] 链表最大孪生和
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
  int pairSum(ListNode* head) {
    vector<int> sum;
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
      sum.push_back(slow->val);
      slow = slow->next;
      fast = fast->next->next;
    }

    int max_sum = 0;
    while (slow) {
      int current_sum = sum.back() + slow->val;
      max_sum = max(max_sum, current_sum);
      sum.pop_back();
      slow = slow->next;
    }

    return max_sum;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */

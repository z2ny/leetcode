/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=
 *
 * [239] 滑动窗口最大值
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
#include <algorithm>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 大根堆不行：无法在left移动时，将该元素移出堆
        // 单调队列，维护可能成为窗口最大值的元素
        // front保持最大值为窗口最大值
        // 加入：从back进队，如果遇到比它小的，就让小的先出队，直到遇到比它大的，这样队列从front到back单调不增
        // 移出：只需要判断窗口移出的元素和front是否相等，相等就pop
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            if (q.empty())
            {
                q.push_back(nums[i]);
            }
            else if (!q.empty())
            {
                while (!q.empty() && q.back() < nums[i])
                {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.push_back(q.front());

        for (int i = k; i < nums.size(); i++)
        {
            if (q.front() == nums[i - k])
            {
                q.pop_front();
            }
            while (!q.empty() && q.back() < nums[i])
            {
                q.pop_back();
            }
            q.push_back(nums[i]);
            res.push_back(q.front());
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=
 *
 * [2589] 完成所有任务的最少时间
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
class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        ranges::sort(tasks, [](auto &a, auto &b)
                     { return a[1] < b[1]; });
        int ans = 0;
        vector<int> run(tasks.back()[1] + 1);
        for (auto &t : tasks)
        {
            int start = t[0], end = t[1], d = t[2];
            d -= reduce(run.begin() + start, run.begin() + end + 1);
            for (int i = end; d > 0; i--)
            {
                if (!run[i])
                {
                    run[i] = true;
                    d--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=
 *
 * [53] 最大子数组和
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
#include <climits>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    // int maxSubArray(vector<int> &nums)
    // {
    //     int p = 0;
    //     int res = INT_MIN;
    //     int temp = 0;

    //     while (p < nums.size())
    //     {
    //         temp += nums[p];
    //         if (temp <= 0)
    //         {
    //             p++;
    //             temp = 0;
    //         }
    //         else
    //         {
    //             p++;
    //         }
    //         res = max(temp, res);
    //     }
    //     return res;
    // }
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int temp = 0;

        for (int p = 0; p < nums.size(); p++)
        {
            temp += nums[p];
            res = max(temp, res);
            if (temp < 0)
            {
                temp = 0;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

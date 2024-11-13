/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>> hp;

        for (auto pair : freq)
        {
            hp.push({pair.second, pair.first});
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(hp.top().second);
            hp.pop();
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

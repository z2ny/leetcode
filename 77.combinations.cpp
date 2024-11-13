/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=
 *
 * [77] 组合
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
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        temp.clear();
        bk(n, k, 1);
        return res;
    }

    void bk(int n, int k, int index)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i <= n; i++)
        {
            temp.push_back(i);
            bk(n, k, i + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 * @lcpr version=
 *
 * [3129] 找出所有稳定的二进制数组 I
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
    int numberOfStableArrays(int zero, int one, int limit)
    {

        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));

        long long mod = 1e9 + 7;

        for (int i = 0; i <= min(zero, limit); i++)
        {
            dp[i][0][0] = 1;
        }

        for (int j = 0; j <= min(one, limit); j++)
        {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i <= zero; i++)
        {
            for (int j = 1; j <= one; j++)
            {
                if (i > limit)
                {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
                }
                else
                {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;

                if (j > limit)
                {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
                }
                else
                {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }

                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n2\n
// @lcpr case=end

 */

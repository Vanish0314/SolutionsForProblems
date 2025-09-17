/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-05 14:54:57
 * @LastEditTime: 2025-09-05 15:10:56
 * // -----------------------------------------------------------------------------
 */
#include <climits>
#include <cstddef>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n+1, 0);

        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;

        dp[0] = 0;
        dp[1] = 1;

        for (size_t i = 2; i <= n; i++)
        {
            int pastMin = INT_MAX;

            int j = 1;
            while (j * j <= i)
            {
                pastMin = min<int>(pastMin, dp[i - j * j]);
                j++;
            }

            dp[i] = pastMin + 1;
        }

        return dp[n];
    }
};
// @lc code=end

int main()
{
    int input = 13;
    Solution s;
    cout << s.numSquares(input);
}
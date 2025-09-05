/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-05 15:14:25
 * @LastEditTime: 2025-09-05 15:29:40
 * // -----------------------------------------------------------------------------
 */

#include <algorithm>
#include <climits>
#include <cstddef>
#include "iostream"
#include "vector"

using namespace std;
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);

        if (amount == 0)
            return 0;

        dp[0] = 0;

        for (size_t i = 1; i <= amount; i++)
        {
            int minCoin = INT_MAX;
            for (size_t j = 0; j < coins.size(); j++)
            {
                int pos = i - coins[j];

                if (pos < 0)
                    continue;

                if (dp[pos] == -1)
                    continue;

                minCoin = min<int>(minCoin, dp[pos] + 1);
            }

            dp[i] = minCoin == INT_MAX ? -1 : minCoin;
        }

        return dp[amount];
    }
};
// @lc code=end

int main()
{
    vector<int> input = {474,83,404,3};
    Solution s;
    cout << s.coinChange(input, 264);
}
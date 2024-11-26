/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount +1,INT_MAX);
        dp[0] = 0; 

        for(int i = 0 ;  i < amount +1 ; i++)
        {
            for(auto coin : coins)
            {
                if(i-coin >= 0 && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i-coin] + 1,dp[i]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end


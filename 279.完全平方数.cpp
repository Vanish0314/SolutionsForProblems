/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + 1;

            int t = 2;
            while( i - t*t >= 0)
            {
                dp[i] = min(dp[i],dp[i-t*t] + 1);
                t++;
            }
        }

        return dp[n];
    }
};
// @lc\ code=end


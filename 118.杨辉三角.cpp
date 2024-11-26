/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        
        if(numRows == 0)
            return dp;
        dp[0] = {1};
        if(numRows == 1)
            return dp;
        dp[1] = {1,1};
        if(numRows == 2)
            return dp;

        for(int i = 2 ;  i < numRows ; i++)
        {
            for(int n = 0 ; n < i + 1 ; n++)
            {
                int left = n-1 < 0 ? 0 : dp[i-1][n-1];
                int right = n == i ? 0 : dp[i-1][n];

                dp[i].emplace_back(left + right);
            }
        }

        return dp;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-10-18 20:10:39
 * @LastEditTime: 2024-10-18 21:17:08
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        
    }

    /// @brief TM用不了动态规划,这是有环图
    /// @param heights 
    /// @return 
    int minimumEffortPath_dp(vector<vector<int>>& heights) {
        // 动态规划
        vector<vector<int>> dp(heights.size() + 1, vector<int>(heights[0].size() + 1, 0));
        dp[0][0] = 0;

        for(int y = 0; y < heights.size(); y++)
        {
            for(int x = 0; x < heights[0].size(); x++)
            {
                if(x == 0 && y == 0)
                    continue;

                int up,down,left,right;
                if(y!=0)
                    up =max(dp[y-1][x],abs(heights[y][x]-heights[y-1][x]));
                else
                    up = INT_MAX;
                if(x!=0)
                    left =max(dp[y][x-1],abs(heights[y][x]-heights[y][x-1]));
                else
                    left = INT_MAX;
                if(y!=heights.size()-1)
                    down =max(dp[y+1][x],abs(heights[y][x]-heights[y+1][x]));
                else
                    down = INT_MAX;
                if(x!=heights[0].size()-1)
                    right =max(dp[y][x+1],abs(heights[y][x]-heights[y][x+1]));
                else
                    right = INT_MAX;

                dp[y][x] = min(min(up,left),min(down,right));
            }
        }

        return dp[heights.size()-1][heights[0].size()-1];
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-09-19 11:51:31
 * @LastEditTime: 2024-09-19 18:25:29
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int x = 1; x < m; x++){
            for(int y = 1; y < n; y++){
                dp[x][y] = dp[x-1][y] + dp[x][y-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// @lc code=end


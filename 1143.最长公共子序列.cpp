/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */


// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        dp[0][0] = text1[0] == text2[0]? 1 : 0;

        for(int i = 1; i < text1.size(); i++)
        {
            dp[i][0] = dp[i-1][0] + (text1[i] == text2[0]? 1 : 0);
            dp[i][0] = min(dp[i][0], 1);
        }
        for(int j = 1; j < text2.size(); j++)
        {
            dp[0][j] = dp[0][j-1] + (text1[0] == text2[j]? 1 : 0);
            dp[0][j] = min(dp[0][j], 1);
        }

        for(int y = 1 ; y < text1.size(); y++)
        {
            for(int x = 1; x < text2.size(); x++)
            {
                int up = dp[y-1][x];
                int left = dp[y][x-1];
                int diag = dp[y-1][x-1] + (text1[y] == text2[x]? 1 : 0);

                if(x == 210 && y == 210)
                    cout << diag << " " << left << " " << up << endl;

                dp[y][x] = max(diag, max(left, up));
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
// @lc code=end
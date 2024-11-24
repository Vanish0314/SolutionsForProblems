/*
 * @Author: Vanish
 * @Date: 2024-11-02 16:42:53
 * @LastEditTime: 2024-11-24 21:41:17
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        if(word1.empty() || word2.empty())
        {
            return max(word1.length(),word2.length());
        }

        vector<vector<int>> dp(word2.length(),vector<int>(word1.length(),INT_MAX));

        dp[0][0] = !(word1[0] == word2[0]);
        for(int y = 1; y < dp.size();y++)
        {
            dp[y][0] = word2[y] == word1[0] ? y : dp[y-1][0] + 1;
        }
        for(int x = 1; x < dp[0].size();x++)
        {
            dp[0][x] = word1[x] == word2[0] ? x : dp[0][x-1] + 1;
                    
        }

        for(int y = 1;y<dp.size();y++)
        {
            for(int x = 1 ; x < dp[0].size() ; x++)
            {
                int add = dp[y][x-1] + 1;
                int minus = dp[y-1][x] + 1;
                int replace = dp[y-1][x-1] + !(word1[x] == word2[y]);

                dp[y][x] = min(replace,min(add,minus));
            }
        }

        return dp[word2.length()-1][word1.length()-1];
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.minDistance("ab","bc");
}
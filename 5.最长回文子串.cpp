/*
 * @Author: Vanish
 * @Date: 2024-11-02 16:42:46
 * @LastEditTime: 2024-11-02 19:44:43
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

//TODO:又没写出来,思路错了

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string inverse = string(s.rbegin(), s.rend());// 反转字符串

        vector<vector<string>> dp (s.size(), vector<string>(s.size(), ""));// dp[i][j]表示(i,j)位置的最长子串

        dp[0][0] = s[0] == inverse[0]? string(1, s[0]) : "";
        for(int i = 1 ; i < s.size() ; i++)
        {
            dp[0][i] = s[0] == inverse[i]? string(1, s[0]) : dp[0][i-1];
        }
        for(int i = 1 ; i < s.size() ; i++)
        {
            dp[i][0] = s[i] == inverse[0]? string(1, s[i]) : dp[i-1][0];
        }

        for(int y = 1; y < s.size() ; y++)
        {
            for(int x = 1; x < s.size() ; x++)
            {
                if(s[x] == inverse[y])
                {
                    dp[x][y] = dp[x-1][y-1] + s[x];
                }
                else
                {
                    dp[x][y] = dp[x-1][y].length() > dp[x][y-1].length() ? dp[x-1][y] : dp[x][y-1];
                }
            }
        }

        return dp[s.size()-1][s.size()-1];
    }
};
// @lc code=end
#include <iostream>
int main()
{
    Solution s;
    string str = "abb";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}

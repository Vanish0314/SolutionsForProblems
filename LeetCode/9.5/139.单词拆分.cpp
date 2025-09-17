#include <algorithm>
#include <cstddef>
#include <string>
#include <unordered_set>
#include "iostream"
#include "set"
#include "string"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (size_t i = 0; i < s.length() + 1; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (dp[i])
                    break;

                string substr = s.substr(j, i - j);
                dp[i] = dp[j] && wordSet.find(substr) != wordSet.end();
            }
        }

        return dp[s.length()];
    }
};
// @lc code=end

int main()
{
    vector<string> input = {"leet", "code"};
    Solution s;
    cout << s.wordBreak("leetcode", input);
}
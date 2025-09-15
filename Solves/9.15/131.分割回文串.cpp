/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-15 15:23:58
 * @LastEditTime: 2025-09-15 15:45:53
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include <string>
#include "iostream"
#include "vector"

using namespace std;
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> results;

    void BackTrack(const string &s, int lastPlacedComma, int commaToPlaceIndex, vector<string> oneSolution)
    {
        if (commaToPlaceIndex == s.length() - 1)
        {
            oneSolution.emplace_back(s.substr(lastPlacedComma + 1, commaToPlaceIndex - lastPlacedComma));

            for (auto s : oneSolution)
            {
                int left = 0, right = s.length() - 1;
                while (left < right)
                {
                    if (s[left++] == s[right--])
                        continue;
                    else
                        return;
                }
            }

            results.emplace_back(oneSolution);
            return ;
        }

        // yes
        oneSolution.emplace_back(s.substr(lastPlacedComma + 1, commaToPlaceIndex - lastPlacedComma));
        BackTrack(s, commaToPlaceIndex, commaToPlaceIndex +1 , oneSolution);
        oneSolution.pop_back();

        // no
        BackTrack(s, lastPlacedComma, commaToPlaceIndex +1 , oneSolution);
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> oneSolution;

        BackTrack(s, -1, 0, oneSolution);

        return results;
    }
};
// @lc code=end

int main()
{
    string s = "aab";

    Solution Solution;
    Solution.partition(s);

    for (auto substr : Solution.results)
    {
        for (auto s : substr)
        {
            cout << " " << s << " ";
        }
        cout << endl;
    }
}
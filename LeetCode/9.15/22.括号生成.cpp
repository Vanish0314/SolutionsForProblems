/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-15 16:43:19
 * @LastEditTime: 2025-09-15 17:18:11
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include <vector>
#include "iostream"
#include "string"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> results;
    string oneSolution = "(";

    void BackTrack(int n,size_t leftCount = 1,size_t rightCount = 0)
    {
        if (n == 0)
        {
            for (size_t i = 0; i < leftCount - rightCount; i++)
                oneSolution.push_back(')');
            results.emplace_back(oneSolution);
            for (size_t i = 0; i < leftCount - rightCount; i++)
                oneSolution.pop_back();
            return;
        }

        // left
        oneSolution.push_back('(');
        BackTrack(n-1,leftCount +1,rightCount);
        oneSolution.pop_back();

        // right
        if(leftCount <= rightCount)
            return;

        oneSolution.push_back(')');
        BackTrack(n,leftCount,rightCount +1);
        oneSolution.pop_back();
    }

    vector<string> generateParenthesis(int n)
    {
        BackTrack(n-1);

        return results;
    }
};
// @lc code=end
int main()
{
    Solution s;
    s.generateParenthesis(3);
}
/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-08 17:11:56
 * @LastEditTime: 2025-09-08 17:50:58
 * // -----------------------------------------------------------------------------
 */
#include "iostream"
#include "stack"
#include "string"

using namespace std;

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxValue = 0;
        stack<int> stack;

        stack.push(-1);
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                stack.pop();
                
                if (stack.empty())
                    stack.push(i);
                else
                    maxValue = max(maxValue, i - stack.top());
            }
        }
        return maxValue;
    }
};
// @lc code=end

int main()
{
    string input = "(()()";

    Solution s;
    cout << s.longestValidParentheses(input);
}
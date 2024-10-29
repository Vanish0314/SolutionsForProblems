/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<string> result;
    void backTrack(int leftCount,int rightCount,int n,string oneSolution)
    {
        if(leftCount==n && rightCount==n)
        {
            result.push_back(oneSolution);
        }

        if(leftCount<n)
        {
            oneSolution.push_back('(');
            backTrack(leftCount+1,rightCount,n,oneSolution);
            oneSolution.pop_back();
        }
        if(rightCount<leftCount)
        {
            oneSolution.push_back(')');
            backTrack(leftCount,rightCount+1,n,oneSolution);
            oneSolution.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        result.clear();
        string oneSolution;
        backTrack(0,0,n,oneSolution);
        return result;
    }
};
// @lc code=end


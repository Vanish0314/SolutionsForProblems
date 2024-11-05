/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!stack.empty() && temperatures[i] > stack.top().first)
            {
                result[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push(make_pair(temperatures[i], i));
        }
        return result;
    }
};
// @lc code=end


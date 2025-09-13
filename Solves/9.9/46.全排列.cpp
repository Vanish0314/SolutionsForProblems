/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-09 14:47:50
 * @LastEditTime: 2025-09-09 15:00:57
 * // -----------------------------------------------------------------------------
 */
#include <climits>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;

    void BackTrack(vector<int> &nums, vector<int> oneSolution)
    {
        if (nums.empty())
        {
            result.emplace_back(oneSolution);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            vector<int> newVec(nums);
            newVec.erase(newVec.begin() + i);

            oneSolution.emplace_back(nums[i]);
            BackTrack(newVec, oneSolution);
            oneSolution.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> oneSolution;
        BackTrack(nums, oneSolution);

        return result;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1, 2, 3};
    Solution s;

    s.permute(input);
}
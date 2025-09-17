/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-16 14:10:05
 * @LastEditTime: 2025-09-17 14:12:16
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include <cstdlib>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    size_t result = 0;
    void BackTrack(vector<int> &nums, int target, int index)
    {
        if (index < 0)
            return;

        if (index == 0 && abs(nums[0]) == abs(target))
        {
            if(nums[0] == 0)
                result++;
            
            result++;
            return;
        }

        BackTrack(nums, target + nums[index], index - 1);
        BackTrack(nums, target - nums[index], index - 1);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        BackTrack(nums, target, nums.size() - 1);

        return result;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {0};

    Solution s;
    cout << s.findTargetSumWays(input, 0);
}
/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-05 14:46:21
 * @LastEditTime: 2025-09-05 14:52:19
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);

        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max<int>(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = max<int>(nums[0], nums[1]);

        for (size_t i = 2; i < nums.size(); i++)
        {
            dp[i] = max<int>(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};
// @lc code=end

int main()
{
    vector<int> input = {2, 7, 9, 3, 1};
    Solution s;
    cout << s.rob(input);
}
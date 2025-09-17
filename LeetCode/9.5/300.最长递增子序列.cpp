/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-05 16:19:42
 * @LastEditTime: 2025-09-05 17:19:24
 * // -----------------------------------------------------------------------------
 */
#include <cstdint>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=300 lang=cpp 
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;

        vector<int> dp(nums.size(), 1);

        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max<int>(dp[i], dp[j] + 1);
                }
            }
        }

        int maxNum = dp[0];
        for (auto i : dp)
            maxNum = max<int>(maxNum, i);

        return maxNum;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution s;
    cout << s.lengthOfLIS(input);
}
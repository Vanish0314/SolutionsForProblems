/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-08 15:43:06
 * @LastEditTime: 2025-09-08 15:57:58
 * // -----------------------------------------------------------------------------
 */
#include <climits>
#include "iostream"
#include "vector"

using namespace std;
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> minDp(nums.size(), INT_MAX);
        vector<int> maxDp(nums.size(), INT_MIN);

        if (nums.empty())
            return -1;

        if (nums.size() == 1)
            return nums[0];

        minDp[0] = nums[0];
        maxDp[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++)
        {
            minDp[i] = min<int>(nums[i], min<int>(nums[i] * maxDp[i - 1], nums[i] * minDp[i - 1]));
            maxDp[i] = max<int>(nums[i], max<int>(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]));
        }

        int maxN = nums[0];
        for (auto i : maxDp)
            maxN = max<int>(maxN, i);
        return maxN;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1, 2, -1, -2, 2, 1, -2, 1, 4, -5, 4};

    Solution s;
    cout << s.maxProduct(input);
}
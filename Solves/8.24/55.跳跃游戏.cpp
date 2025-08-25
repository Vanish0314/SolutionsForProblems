/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-24 14:41:39
 * @LastEditTime: 2025-08-24 15:25:57
 * // -----------------------------------------------------------------------------
 */

#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = nums[0];

        for (int i = 0; i < nums.size() && maxReach >= i; i++)
            maxReach = max<int>(i + nums[i], maxReach);

        return maxReach >= nums.size() - 1;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {2, 0, 0};

    Solution s;
    cout << s.canJump(input);
}
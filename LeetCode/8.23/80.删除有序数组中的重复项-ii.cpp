/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-23 18:12:56
 * @LastEditTime: 2025-08-23 18:38:42
 * // -----------------------------------------------------------------------------
 */

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        static const size_t jumpGap = 2;

        size_t slow = 0;
        size_t fast = 0;

        while (fast < nums.size())
        {
            size_t currentNumCount = 1;
            int currentNum = nums[fast];

            while (++fast < nums.size() && nums[fast] == currentNum)
                currentNumCount++;

            for (size_t i = 0; i < min<size_t>(jumpGap, currentNumCount); i++)
                nums[slow++] = currentNum;
        }

        return slow;
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {1};
    Solution s;
    auto num = s.removeDuplicates(nums);
    cout << num << endl;

    for (size_t i = 0; i < num; i++)
        cout << nums[i] << " ";
}
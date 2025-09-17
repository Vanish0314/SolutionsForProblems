/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-23 18:03:22
 * @LastEditTime: 2025-08-23 18:12:00
 * // -----------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        size_t slow = 0;
        size_t fast = 0;

        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }

            fast++;
        }

        return ++slow;
    }
};
// @lc code=end

int main()
{
    vector<int> source = {1, 1, 2};

    Solution s;
    cout << s.removeDuplicates(source);
}
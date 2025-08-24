/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-23 17:59:44
 * @LastEditTime: 2025-08-23 18:02:44
 * // -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        int fast = 0;

        while(fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};
// @lc code=end

int main()
{
}
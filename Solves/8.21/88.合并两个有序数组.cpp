/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-21 20:30:45
 * @LastEditTime: 2025-08-21 21:40:10
 * // -----------------------------------------------------------------------------
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int ptr1 = m - 1;
        int ptr2 = n - 1;

        for (size_t i = m + n - 1; i >= 0; i--)
        {
            if (ptr1 >= 0 && ptr2 >= 0)
            {
                nums1[i] = nums1[ptr1] > nums2[ptr2] ? nums1[ptr1--] : nums2[ptr2--];
            }
            else
            {
                nums1[i] = ptr1 >= 0 ? nums1[ptr1--] : ptr2 >= 0 ? nums2[ptr2--] : nums1[i];
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);

    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1};
    vector<int> nums4 = {};

    solution.merge(nums3, 1, nums4, 0);
    for (int num : nums3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

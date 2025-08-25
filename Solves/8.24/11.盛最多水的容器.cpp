/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-24 14:41:14
 * @LastEditTime: 2025-08-24 15:14:25
 * // -----------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "vector"
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        size_t left = 0;
        size_t right = height.size() - 1;

        size_t maxArea = min<int>(height[left], height[right]) * right;
        while (true)
        {
            size_t shortOne = min<int>(height[left], height[right]);
            size_t oldLeft = left;
            size_t oldRight = right;

            if (height[left] < height[right])
            {
                for (size_t i = left; i < right; i++)
                {
                    if (height[i] > shortOne)
                    {
                        left = i;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                for (size_t i = right; i > left; i--)
                {
                    if (height[i] > shortOne)
                    {
                        right = i;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            maxArea = max(maxArea, min(height[right], height[left]) * (right - left));

            if (oldLeft == left && oldRight == right)
                return maxArea;
        }

        return maxArea;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;
    cout << s.maxArea(input);
}
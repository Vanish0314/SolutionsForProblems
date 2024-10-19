/*
 * @Author: Vanish
 * @Date: 2024-09-11 18:45:24
 * @LastEditTime: 2024-09-11 18:56:54
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;

        while(left < right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max)
            {
                water += left_max - height[left];
                left++;
            }
            else
            {
                water += right_max - height[right];
                right--;
            }
        }

        return water;
    }
};
// @lc code=end


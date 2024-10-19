/*
 * @Author: Vanish
 * @Date: 2024-09-20 20:24:32
 * @LastEditTime: 2024-09-20 21:05:59
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;

        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i + nums[i] >= maxReach)
            {
                if(nums[i] == 0 && i != nums.size() - 1)
                    return false;
                maxReach = i + nums[i];
            }
        }

        if(maxReach < nums.size() - 1)
            return false;
        return true;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-09-19 11:17:52
 * @LastEditTime: 2024-09-19 11:23:09
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return dp[nums.size()];
    }
};
// @lc code=end


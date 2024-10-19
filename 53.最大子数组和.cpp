/*
 * @Author: Vanish
 * @Date: 2024-09-20 19:28:15
 * @LastEditTime: 2024-09-20 19:29:31
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            max_sum = max(max_sum,dp[i]);
        }
        return max_sum;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-09-19 11:28:41
 * @LastEditTime: 2024-09-19 11:47:49
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        vector<int> dp = {0, nums[0]};
        m[nums[0]] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            ++m[nums[i]];
            if(nums[i] != dp.back())
                dp.push_back(nums[i]);
        }

        int last = dp[1];
        dp[1] = dp[1] * m[dp[1]];
        for(int i = 2; i < dp.size(); ++i)
        {
            if(dp[i] - last == 1)
            {
                last = dp[i];
                dp[i] = max(dp[i-1], dp[i-2] + dp[i] * m[dp[i]]);
            }
            else
            {
                last = dp[i];
                dp[i] = dp[i-1] + dp[i] * m[dp[i]];
            }
        }

        return dp[dp.size() - 1];
    }
};

// 这题不是很理解
// @lc code=end


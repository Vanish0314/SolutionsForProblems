/*
 * @Author: Vanish
 * @Date: 2024-10-19 15:11:56
 * @LastEditTime: 2024-10-19 15:14:51
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

// TODO: 过不了,卡时间了

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0,right = k-1;
        vector<int> res(nums.size() - k + 1);

        int preMax = nums[0];
        for(int i = 1; i <= k; i++)
        {
            preMax = max(preMax, nums[i]);
        }
        res.push_back(preMax);

        while(right < nums.size())
        {
            left++;
            right++;
            preMax = max(preMax, nums[right]);
            res.push_back(preMax);
        }

        return res;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-09-11 18:11:57
 * @LastEditTime: 2024-09-11 18:37:32
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i =0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int target = -nums[i];

            int low = i+1;
            int high = nums.size()-1;
            while(low < high)
            {
                if(nums[low] + nums[high] > target)
                    high--;
                else if(nums[low] + nums[high] < target)
                    low++;
                else
                {
                    res.push_back({nums[i],nums[low],nums[high]});
                    low++;high--;
                    while(nums[low] == nums[low-1] && low < high)
                        low++;
                    while(nums[high] == nums[high+1] && low < high)
                        high--;
                }
            }
        
        }

        return res;
    }
};
// @lc code=end


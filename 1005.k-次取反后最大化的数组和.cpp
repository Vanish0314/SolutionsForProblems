/*
 * @Author: Vanish
 * @Date: 2024-09-20 21:07:59
 * @LastEditTime: 2024-09-20 21:47:00
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        if(k > nums.size()) k = nums.size() + (k - nums.size())%2 -2;
        
        int i = 0;
        for(;i<k;i++)
        {
            if(nums[i] < 0)
                nums[i] = -nums[i];
            else
                break;
        }
        if(i < k)
        {
            if((k-i) % 2 != 0)
            {
                int n = nums[i] > nums[i-1 <0 ? i+1 : i-1] ? i-1 : i;
                nums[n] = -nums[n];
            }
        }

        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end


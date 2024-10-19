/*
 * @Author: Vanish
 * @Date: 2024-09-18 19:15:10
 * @LastEditTime: 2024-09-18 19:30:55
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution1_sort {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num : nums)
            num *= num;
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num : nums)
            num *= num;

        int left = 0, right = nums.size() - 1;
        vector<int> res(nums.size());
        int i = nums.size() - 1;
        while(left <= right) {
            if(nums[left] > nums[right]) {
                res[i--] = nums[left];
                left++;
            } else {
                res[i--] = nums[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end


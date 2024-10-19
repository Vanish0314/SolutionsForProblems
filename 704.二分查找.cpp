/*
 * @Author: Vanish
 * @Date: 2024-09-18 18:46:46
 * @LastEditTime: 2024-09-18 19:35:59
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
// @lc code=end


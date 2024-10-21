/*
 * @Author: Vanish
 * @Date: 2024-10-21 21:56:28
 * @LastEditTime: 2024-10-21 21:56:41
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums)
            res ^= num;
        return res;
    }
};
// @lc code=end


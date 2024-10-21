/*
 * @Author: Vanish
 * @Date: 2024-10-21 21:43:28
 * @LastEditTime: 2024-10-21 21:44:27
 * Also View: http://vanishing.cc
 * Contract Me: qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        char count = 0;
        for(int i = 0; i < 32 ; i++)
        {
            if(n & (1 << i))
                count++;
        }
        return count;
    }
};
// @lc code=end


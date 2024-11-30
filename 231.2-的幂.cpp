/*
 * @Author: Vanish
 * @Date: 2024-10-21 21:49:49
 * @LastEditTime: 2024-11-27 16:21:12
 * Also View: http://vanishing.cc
 * Contract Me: qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

//TIP:位运算示例
// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
            
        int count=0;
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i))
                count++;
        }
        return count==1;
    }
};
// @lc code=end


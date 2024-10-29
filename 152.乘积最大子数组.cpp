/*
 * @Author: Vanish
 * @Date: 2024-10-29 19:14:28
 * @LastEditTime: 2024-10-29 19:59:46
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

//TODO: 没写出来

/*
解题思路
标签：动态规划
遍历数组时计算当前最大值，不断更新
令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
当负数出现时则imax与imin进行交换再进行下一步计算
时间复杂度：O(n)

作者：画手大鹏
链接：https://leetcode.cn/problems/maximum-product-subarray/solutions/7561/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


这个思路太好了,尤其是:由于存在负数，那么会导致最大的变最小的，最小的变最大的  让人幡然醒悟
*/

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if(nums.size() == 1) return dp[0];
        dp[1] = max(dp[0]*nums[1],nums[1]);
        if(nums.size() == 2) return dp[1];

        vector<int> miuns(nums.size());
        vector<int> positives(nums.size());

        miuns[0] = nums[0];
        miuns[1] = miuns[0]*nums[1];

        for(int i=2;i<nums.size();i++)
        {
            miuns[i] = miuns[i-1]*nums[i];

            dp[i] = max(miuns[i-1] * nums[i],dp[i-1]);
            // dp[i] = max(dp[i],dp[i-1]);
            dp[i] = max(dp[i],nums[i]);
        }

        return *max_element(dp.begin(),dp.end());
    }
};

// @lc code=end

#include <iostream>
int main()
{
    Solution s;
    vector<int> nums = {2,-5,-2,-4,3};
    cout<<s.maxProduct(nums)<<endl;
    return 0;
}

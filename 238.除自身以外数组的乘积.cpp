/*
 * @Author: Vanish
 * @Date: 2024-11-25 23:43:01
 * @LastEditTime: 2024-11-26 00:03:48
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> front(n,0),back(n,0);

        front[0]= nums[0];
        for(int i = 1 ; i < n; i++)
        {
            front[i] = (front[i-1] * nums[i]);
        }
        back[n-1] = nums[n-1];
        for(int i = n-2; i >= 0 ; i--)
        {
            back[i] = back[i+1] * nums[i];
        }

        vector<int> res(n,0);
        res[0] = back[1];
        res[n -1] = front[n -2];
        for(int i = 1 ; i < n - 1; i++)
        {
            res[i] = front[i-1] * back[i+1];
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> input = {1,2,3,4};
    s.productExceptSelf(input);
}
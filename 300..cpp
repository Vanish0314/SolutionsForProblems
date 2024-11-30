/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size());

        dp[0] = {nums[0]};
        for(int i = 1; i < nums.size(); i++)
        {
            vector<int> vec = dp[i-1];
            int num = nums[i];
            int length = dp[i-1].size();
            if(num > dp[i-1][length - 1])
            {
                vec.emplace_back(num);
                dp[i] = vec;
            }
            else
            {
                if(length >=2 && num <= dp[i-1][length -2])
                {
                    dp[i] = vec;
                    continue;
                }
                vec.pop_back();
                vec.emplace_back(num);
                dp[i] = vec;
            }
        }

        return dp[nums.size()-1].size();
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    s.lengthOfLIS(nums);
}
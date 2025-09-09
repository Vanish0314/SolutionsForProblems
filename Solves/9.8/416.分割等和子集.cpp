#include <climits>
#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return false;

        int sum = 0;
        for (auto i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

        for (size_t i = 0; i < nums.size(); i++)
            dp[i][0] = 0;
        for (size_t i = 0; i <= target; i++)
            dp[0][i] = i >= nums[0] ? nums[0] : 0;

        for (size_t i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= target; j++)
            {
                int notTake = dp[i - 1][j];
                int take = j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] + nums[i] : 0;
                dp[i][j] = max<int>(take, notTake);
            }
        }

        return dp[nums.size() - 1][target] == target;
    }
};
// @lc code=end

int main()
{
    vector<int> input = {1, 5, 11, 5};

    Solution s;
    cout << s.canPartition(input);
}
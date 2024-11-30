/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> input = {1,2,3,4,5,6,7};
    s.rotate(input, 3);
}
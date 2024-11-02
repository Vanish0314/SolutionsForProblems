/*
 * @Author: Vanish
 * @Date: 2024-11-02 16:43:14
 * @LastEditTime: 2024-11-02 19:51:12
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    void BackTrack(vector<int> nums,vector<int> &oneSolution)
    {
        if(nums.size() == 0)
        {
            result.push_back(oneSolution);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> newNums(nums);
            newNums.erase(newNums.begin() + i);
            oneSolution.push_back(nums[i]);
            BackTrack(newNums,oneSolution);
            oneSolution.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> oneSolution;
        BackTrack(nums,oneSolution);
        return result;
    }
};
// @lc code=end


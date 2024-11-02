/*
 * @Author: Vanish
 * @Date: 2024-11-02 16:43:20
 * @LastEditTime: 2024-11-02 20:16:58
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    void BackTrack(vector<int> nums,vector<int> &oneSolution,int index,bool isSelected)
    {
        if(index == nums.size())
        {
            if(isSelected)
                result.emplace_back(oneSolution);
            return;
        }

        if(isSelected)
        {
            oneSolution.emplace_back(nums[index]);
            BackTrack(nums,oneSolution,index+1,true);
            BackTrack(nums,oneSolution,index+1,false);
            oneSolution.pop_back();
        }
        else
        {
            BackTrack(nums,oneSolution,index+1,true);
            BackTrack(nums,oneSolution,index+1,false);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> oneSolution;
        BackTrack(nums,oneSolution,0,false);
        BackTrack(nums,oneSolution,0,true);
        return result;
    }
};
// @lc code=end
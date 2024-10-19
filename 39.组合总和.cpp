/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

private:

    void BackTrack(int target,vector<int> &nums,int start,vector<int> &oneSoulution)
    {
        if(target == 0)
        {
            res.push_back(oneSoulution);
            return;
        }

        for(int i = start;i < nums.size();i++)
        {
            if(nums[i] > target)
                continue;
            oneSoulution.push_back(nums[i]);
            BackTrack(target - nums[i],nums,i,oneSoulution);
            oneSoulution.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> oneSoulution;
        sort(candidates.begin(),candidates.end());
        BackTrack(target,candidates,0,oneSoulution);
        return res;
    }
};
// @lc code=end


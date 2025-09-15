/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-15 15:01:49
 * @LastEditTime: 2025-09-15 15:22:09
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
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

int main()
{
    int size = 14;

    vector<int> input(size);
    for(size_t i = 0; i < size; i++)
        input.emplace_back(i);

    Solution s;

    cout<< "Calculating"<<endl;
    
    s.subsets(input);
    
    cout<< "Calculating Done"<<endl;

    for (auto vec : s.result)
    {
        cout << "[";

        for (auto num : vec)
            cout << " " << num;

        cout << " ]";
    }
}
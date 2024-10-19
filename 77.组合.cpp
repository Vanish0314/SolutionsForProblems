/*
 * @Author: Vanish
 * @Date: 2024-09-19 20:05:35
 * @LastEditTime: 2024-09-19 20:10:08
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res = {};

private:
    void BackTrack(int n,int k,int start,vector<int> &oneSolution)
    {
        if(k == 0)
        {
            res.push_back(oneSolution);
            return;
        }

        for(int i = start; i <= n; i++)
        {
            oneSolution.push_back(i);
            BackTrack(n,k-1,i+1,oneSolution);
            oneSolution.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> oneSolution;
        BackTrack(n,k,1,oneSolution);
        return res;
    }
};
// @lc code=end


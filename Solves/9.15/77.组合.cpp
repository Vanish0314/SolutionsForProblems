/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-15 15:53:56
 * @LastEditTime: 2025-09-15 16:11:39
 * // -----------------------------------------------------------------------------
 */
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> oneSolution;

    void BackTrack(int n, int k )
    {
        if(oneSolution.size() + n < k)
            return;

        if(n == 0 && k != 0)
            return;
        
        if(k == 0)
        {
            results.emplace_back(oneSolution);
            return;
        }

        // yes
        oneSolution.emplace_back(n);
        BackTrack(n-1, k - 1);
        oneSolution.pop_back();

        // no
        BackTrack(n-1, k);
    }

    vector<vector<int>> combine(int n, int k)
    {
        BackTrack(n, k);

        return results;
    }
};
// @lc code=end

int main()
{
    int n = 20,k = 10;

    Solution s;
    s.combine(n, k);
}
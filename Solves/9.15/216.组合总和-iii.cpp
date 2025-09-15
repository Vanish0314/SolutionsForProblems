#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> oneSoulution;

    void BackTrack(int num, int k, int n)
    {
        if(num < 0 || n < 0)
            return;

        if (n == 0)
        {
            if(k==0)
                results.emplace_back(oneSoulution);
            return;
        }

        num = std::min<int>(num,n);

        // yes
        oneSoulution.emplace_back(num);
        BackTrack(num - 1, k - 1, n - num);
        oneSoulution.pop_back();

        // no
        BackTrack(num - 1, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        BackTrack(9, k, n);

        return results;
    }
};
// @lc code=end

int main()
{
    Solution s;

    s.combinationSum3(3, 7);
}
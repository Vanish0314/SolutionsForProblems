/*
 * @Author: Vanish
 * @Date: 2024-10-24 19:10:39
 * @LastEditTime: 2024-10-24 19:58:22
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for(int i = 0; i < intervals.size(); i++)
        {
            int min = intervals[i][0];
            int max = intervals[i][1];

            int j = 1;
            while(i+j < intervals.size() && max>=intervals[i+j][0] )
            {
                max = std::max(intervals[i+j][1],max);
                j++;
            }
            res.push_back({min,max});
            i += j-1;
        }
        return res;
    }
};
// @lc code=end


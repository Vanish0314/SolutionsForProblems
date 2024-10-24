/*
 * @Author: Vanish
 * @Date: 2024-10-24 19:10:56
 * @LastEditTime: 2024-10-24 19:38:08
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start'

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        for(int y = 0; y < matrix.size(); y++)
        {
            for(int x = 0; x < matrix[0].size(); x++)
            {
                if(matrix[y][x] == 0)
                    zeros.push_back(make_pair(x,y));
            }
        }

        for(auto zero : zeros)
        {
            int x = zero.first;
            int y = zero.second;
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][x] = 0;
            }
            for(int j = 0; j < matrix[0].size(); j++)
            {
                matrix[y][j] = 0;
            }
        }
    }
};
// @lc code=end


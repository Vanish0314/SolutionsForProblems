/*
 * @Author: Vanish
 * @Date: 2024-09-20 21:50:00
 * @LastEditTime: 2024-09-20 22:07:39
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int calculateArea(int x ,int y, vector<vector<int>>& grid)
    {
        if(grid[x][y]==0) return 0;

        grid[x][y]=2;
        int area=1;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1)
            {
                area+=calculateArea(nx,ny,grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    max_area=max(max_area,calculateArea(i,j,grid));
                }
            }
        }
        return max_area;
    }
};
// @lc code=end


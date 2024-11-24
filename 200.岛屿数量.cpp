/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        if(y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size())
            return;
        if(grid[y][x] == '0')
            return;

        grid[y][x] = '0';
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int y = 0; y < grid.size(); y++)
        {
            for(int x = 0; x < grid[0].size(); x++)
            {
                if(grid[y][x] == '1')
                {
                    dfs(grid, x, y);
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end


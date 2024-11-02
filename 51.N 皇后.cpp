/*
 * @Author: Vanish
 * @Date: 2024-10-29 19:14:21
 * @LastEditTime: 2024-11-02 10:55:00
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

//TODO:没写完

#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<pair<int, int>>> solvesOfNQueens;

    void BackTrack(int n, int queenCount, int x, int y, vector<int> &row, vector<int> &col, vector<pair<int, int>> &oneSolution)
    {
        if (row[x] || col[y])
        {
            return;
        }
        if (queenCount == n)
        {
            solvesOfNQueens.emplace_back(oneSolution);
            return;
        }

        for(int ny = 0; ny < n; ny++)
        {
            for(int nx = 0; nx < n; nx++)
            {
                oneSolution.emplace_back(make_pair(x,y));
                row[x] = true;
                col[y] = true;
                BackTrack(n,queenCount+1,nx,ny,row,col,oneSolution);
                row[x] = false;
                col[y] = false;
                oneSolution.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n,0),col(n,0);
        vector<pair<int,int>> oneSolution;
        BackTrack(n,1,0,0,row,col,oneSolution);

        vector<vector<string>> result;
        for(auto &solution : solvesOfNQueens)
        {
            vector<string> board(n,string(n,'.'));
            for(auto &queen : solution)
            {
                board[queen.first][queen.second] = 'Q';
            }
            result.emplace_back(board);
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}

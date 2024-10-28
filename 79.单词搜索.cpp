/*
 * @Author: Vanish
 * @Date: 2024-10-28 19:15:25
 * @LastEditTime: 2024-10-28 19:56:32
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y,vector<bool> &visited)
    {
        if(word.empty())
            return true;

        if(x>=0 && x<board[0].size() && y>=0 && y<board.size())
        {
            if(visited[y*board[0].size()+x])
                return false;

            if(board[y][x] == word[0])
            {
                string temp = word.substr(1);
                visited[y*board[0].size()+x] = true;
                for(int i = 0; i < 4; i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(dfs(board,temp,nx,ny,visited))
                        return true;
                }
                visited[y*board[0].size()+x] = false;
            }
        }
        return false;
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    bool exist(vector<vector<char>>& board, string word) {
        vector<bool> visited(board.size()*board[0].size(), false); //(x,y) equals y*n+x

        for(int y = 0; y < board.size(); y++)
        {
            for(int x = 0; x < board[0].size(); x++)
            {
                if(board[y][x] == word[0])
                {
                    if(dfs(board,word,x,y,visited))
                        return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-10-10 13:38:55
 * @LastEditTime: 2024-10-10 14:12:24
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool CheckLine(vector<char> &line)
    {
        int num[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (line[i] != '.')
            {
                if (num[line[i] - '1'] > 0)
                    return false;
                num[line[i] - '1']++;
            }
        }
        return true;
    }
    bool CheckColum(vector<vector<char>> &board, int col)
    {
        int num[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.')
            {
                if (num[board[i][col] - '1'] > 0)
                    return false;
                num[board[i][col] - '1']++;
            }
        }
        return true;
    }
    bool CheckBlock(vector<vector<char>> &board)
    {
        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 3; n++)
            {
                int num[9] = {0};
                for (int l = 0; l < 3; l++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        if (board[m * 3 + l][n * 3 + c] != '.')
                        {
                            if (num[board[m * 3 + l][n * 3 + c] - '1'] > 0)
                                return false;
                            num[board[m * 3 + l][n * 3 + c] - '1']++;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (!CheckLine(board[i]))
                return false;
            if (!CheckColum(board, i))
                return false;
        }
        return CheckBlock(board);
    }
};

// int main()
// {
//     Solution s;
//     //[[".",".",".",".","5",".",".","1","."],[".","4",".","3",".",".",".",".","."],[".",".",".",".",".","3",".",".","1"],["8",".",".",".",".",".",".","2","."],[".",".","2",".","7",".",".",".","."],[".","1","5",".",".",".",".",".","."],[".",".",".",".",".","2",".",".","."],[".","2",".","9",".",".",".",".","."],[".",".","4",".",".",".",".",".","."]]
//     vector<vector<char>> board = {
//         {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
//         {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
//         {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
//         {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
//         {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
//         {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
//         {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
//         {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
//         {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

//     cout << s.isValidSudoku(board) << endl;
// }
// @lc code=end

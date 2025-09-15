/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-15 17:20:53
 * @LastEditTime: 2025-09-15 18:13:30
 * // -----------------------------------------------------------------------------
 */
#include <cstddef>
#include <string>
#include <vector>
#include "iostream"
#include "string"
#include "vector"

using namespace std;

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> results;
    vector<string> oneSolution;

    vector<int> row;
    vector<int> col;
    vector<int> diag;
    vector<int> reverseDiag;
    size_t n = 0;
    void Init(int n)
    {
        string str;
        for (int i = 0; i < n; i++)
            str += ".";

        oneSolution = vector<string>(n, str);

        row = vector<int>(n, 0);
        col = vector<int>(n, 0);
        diag = vector<int>(2 * n - 1, 0);
        reverseDiag = vector<int>(2 * n - 1, 0);

        this->n = n;
    }

    void PlaceQueen(int x, int y)
    {
        col[x]++;
        row[y]++;
        diag[x + y]++;
        reverseDiag[n - 1 + x - y]++;
    }

    void RemoveQueen(int x, int y)
    {
        col[x]--;
        row[y]--;
        diag[x + y]--;
        reverseDiag[n - 1 + x - y]--;
    }

    void BackTrack(size_t placedQueen = 0, size_t x = 0, size_t y = 0)
    {
        if (placedQueen == n)
        {
            results.emplace_back(oneSolution);
            return;
        }

        if (x >= n)
        {
            x = 0;
            y++;
        }

        if (y > n - 1)
            return;

        while (col[x] > 0 || row[y] > 0 || diag[x + y] > 0 || reverseDiag[n - 1 + x - y] > 0)
        {
            x++;

            if (x >= n)
            {
                x = 0;
                y++;
            }

            if (y > n - 1)
                return;
        }

        // yes
        oneSolution[y].replace(x, 1, "Q");
        PlaceQueen(x, y);
        BackTrack(placedQueen + 1, x + 1, y);
        RemoveQueen(x, y);
        oneSolution[y].replace(x, 1, ".");

        // no
        BackTrack(placedQueen, x + 1, y);
    }

    vector<vector<string>> solveNQueens(int n)
    {
        Init(n);

        BackTrack();

        return results;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.solveNQueens(4);

    int i = 0;
    for (auto solves : s.results)
    {
        cout << "=====Solve " << i++ << "=====" << endl;

        for (auto solve : solves)
        {
            cout << solve << endl;
        }

        cout << "=================" << endl << endl;
    }
}
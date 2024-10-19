/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        if(n==1)
            return vector<vector<int>>{{1}};

        vector<vector<int>> res(n,vector<int>(n));//初始化矩阵

        int num = 1;
        int offset = 0;

        for(int i = 0 ; i < n/2 ; i++)
        {
            //从左到右
            for(int x = offset ; x < n - 1 - offset ; x++)
                res[offset][x] = num++;
            
            //从上到下
            for(int y = offset ; y < n - 1 - offset ; y++)
                res[y][n-1-offset] = num++;

            //从右到左
            for(int x = n-1-offset ; x > offset ; x--)
                res[n-1-offset][x] = num++;

            //从下到上
            for(int y = n-1-offset ; y > offset ; y--)
                res[y][offset] = num++;

            offset++;
        }

        if(n%2==1)
            res[n/2][n/2] = num;

        return res;
    }
};
// @lc code=end


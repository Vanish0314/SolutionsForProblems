/*
 * @Author: Vanish
 * @Date: 2024-11-30 14:04:59
 * @LastEditTime: 2024-11-30 16:12:57
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up=0,left=0;
        int down = matrix.size()-1;
        int right = matrix[0].size()-1;
        vector<int> res;
        res.reserve((down+1)*(right+1));

        int c = (max(down,right)+2)/2;
        int x=0 ,y=0;
        while(true)
        {
            for(x = left ; x <=right ; x++)
            {
                res.emplace_back(matrix[y][x]);
            }
            x--;
            up++;
            if(up > down)
                break;

            for(y = up ; y<=down ; y++)
            {
                res.emplace_back(matrix[y][x]);
            }
            y--;
            right--;
            if(left > right)
                break;

            for(x = right; x>=left; x--)
            {
                res.emplace_back(matrix[y][x]);
            }
            x++;
            down--;
            if(up > down)
                break;

            for(y = down; y >= up ; y--)
            {
                res.emplace_back(matrix[y][x]);
            }
            y++;
            left++;
            if(left > right)
                break;
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s; 
    vector<vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> res = s.spiralOrder(input);

    for(auto n : res)
        std::cout<<n<<" ";
}


/*
 * @Author: Vanish
 * @Date: 2024-09-21 19:50:52
 * @LastEditTime: 2024-09-21 20:36:42
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    double champagneTower(int poured, int query_row, int query_glass) {
         vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1, 0));
        tower[0][0] = poured; // 初始化第一杯

        for (int r = 0; r <= query_row; ++r) {
            for (int g = 0; g <= r; ++g) {
                // 只处理填满的杯子
                if (tower[r][g] > 1) {
                    double excess = tower[r][g] - 1; // 溢出部分
                    tower[r][g] = 1; // 设置为最大值
                    if (r + 1 <= query_row) {
                        tower[r + 1][g] += excess / 2; // 左下杯子
                        tower[r + 1][g + 1] += excess / 2; // 右下杯子
                    }
                }
            }
        }

        return tower[query_row][query_glass]; // 返回目标杯子中的香槟量
    }
};
// @lc code=end


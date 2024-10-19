/*
 * @Author: Vanish
 * @Date: 2024-09-20 19:18:23
 * @LastEditTime: 2024-09-20 19:20:26
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, res = 0;

        while (i < g.size() && j < s.size()) 
        {
            if(s[j] >= g[i])
            {
                res++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return res;
    }
};
// @lc code=end


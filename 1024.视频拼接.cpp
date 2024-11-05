/*
 * @Author: Vanish
 * @Date: 2024-11-04 21:11:55
 * @LastEditTime: 2024-11-05 21:19:58
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

//TODO: 玛德为什么本地ok提交有问题

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b)->bool{
            return a[0] == b[0] ? a[1]<b[1] : a[0]<b[0];
        });
        if(clips[0][0] > 0)
            return -1;

        vector<int> dp(clips[clips.size()-1][1]+1,INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < clips.size(); i++)
        {
            int start = clips[i][0];
            int end = clips[i][1];
            int n = dp[start] + 1;
            for(int j = start; j <= end; j++)
            {
                dp[j] = min(dp[j], n);
            }
        }
        
        return dp[time] == INT_MAX? -1 : dp[time];
    }
};
// @lc code=end
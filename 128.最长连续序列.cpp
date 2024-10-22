/*
 * @Author: Vanish
 * @Date: 2024-10-22 18:59:50
 * @LastEditTime: 2024-10-22 19:46:06
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        nums.assign(st.begin(), st.end());

        int maxLen = 1;
        int curLen = 0;
        for(int i : nums)
        {
            if(s.count(i - 1) && !s.count(i + 1))
            {
                curLen = 2;
                int j = i - 1;
                while(s.count(j - 1))
                {
                    j--;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
// @lc code=end


/*
 * @Author: Vanish
 * @Date: 2024-10-22 19:51:51
 * @LastEditTime: 2024-10-22 19:53:46
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();

        int left = 0 ,right = 1;
        int maxLen = 1;

        unordered_set<char> set;
        set.insert(s[0]);

        while(right < s.size())
        {
            char c = s[right];
            if(!set.count(c))
            {
                set.insert(c);
                right++;
                maxLen = max(maxLen, right - left);
            }
            else
            {
                set.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
// @lc code=end


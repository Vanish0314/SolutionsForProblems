/*
 * @Author: Vanish
 * @Date: 2024-10-22 19:58:27
 * @LastEditTime: 2024-10-22 20:33:40
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

/*
麻了,写完了才发现,p中某一字母出现次数可以大于1,所以不能用位运算来判断是否异位,只能用哈希表来统计字母出现次数
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int width = p.length();
        vector<int> res;
        int target = 0;
        int cur = 0;

        for (char c : p) {
            target |= 1 << (c - 'a');
        }
        for (int i = 0; i < width && i < s.length(); i++) {
            cur |= 1 << (s[i] - 'a');
        }

        for (int left = 0; left <= s.length() - width; left++) {
            if (cur == target) {
                res.push_back(left);
            }
            if (left + width < s.length()) {
                // cur &= ~(1 << (s[left] - 'a')); // 移除左边的字符
                // cur |= 1 << (s[left + width] - 'a'); // 添加右边的新字符
                cur = 0;
                left++;
                for(int n = 0; n < width; n++)
                {
                    cur |= 1 << (s[left + n] - 'a');
                }
                left--;
            }
        }
        
        return res;
    }
};

// @lc code=end


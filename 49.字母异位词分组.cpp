/*
 * @Author: Vanish
 * @Date: 2024-09-10 21:51:53
 * @LastEditTime: 2024-09-10 22:08:40
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            if(mp.find(key) == mp.end())
            {
                mp[key].push_back(s);
            }
            else
            {
                mp[key].push_back(s);
            }
        }

        vector<vector<string>> result;
        for(auto& p : mp)
        {
            result.push_back(p.second);
        }
        return result;
    }
};
// @lc code=end


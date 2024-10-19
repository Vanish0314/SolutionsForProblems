/*
 * @Author: Vanish
 * @Date: 2024-10-10 15:27:24
 * @LastEditTime: 2024-10-10 15:42:44
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start

#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        auto split = [](const string &s, char delim) -> vector<string>
        {
            vector<string> ans;
            string cur;
            for (char ch : s)
            {
                if (ch == delim)
                {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else
                {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string &name : names)
        {
            if (name == "..")
            {
                if (!stack.empty())
                {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".")
            {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty())
        {
            ans = "/";
        }
        else
        {
            for (string &name : stack)
            {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};
// @lc code=end

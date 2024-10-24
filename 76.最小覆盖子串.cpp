/*
 * @Author: Vanish
 * @Date: 2024-10-24 19:09:52
 * @LastEditTime: 2024-10-24 20:17:48
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:


    /// @brief 返回不足字符
    /// @param need 
    /// @param window 
    /// @return 
    char Check(unordered_map<char,int>& need, unordered_map<char,int>& window)
    {
        for(auto& p:need)
        {
            if(window[p.first]<p.second)
                return p.first;
        }
        return 1;//返回1则表示足了.
    }
    string minElm(vector<string> &s)
    {
        int minLen = INT_MAX;
        int minLenIndex = -1;

        for(int i = 0;i<s.size();i++)   
        {
            if(s[i].length()<minLen)
            {
                minLen = s[i].length();
                minLenIndex = i;
            }
        }

        return s[minLenIndex];
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;

        for(char c:t)
        {
            need[c]++;
        }
        
        int left = 0,right =0;
        window[s[0]]++;
        int len = s.length();
        vector<string> res;
        bool flag = false;
        while(right<len)
        {
            char c = Check(need,window);

            if(c != 1)
            {
                if(flag)
                {
                    res.push_back(s.substr(left-1,right-left+2));
                    flag = false;
                }
                right++;
                window[s[right]]++;
            }
            else
            {
                flag = true;
                window[s[left]]--;
                left++;
            }
        }
        if(res.size() == 0)
            return "";
        
        return minElm(res);
    }
};

// int main()
// {
//     Solution s;
//     string s1 = "ADOBECODEBANC";
//     string t1 = "ABC";

//     s.minWindow(s1,t1);

//     return 0;
// }
// @lc code=end


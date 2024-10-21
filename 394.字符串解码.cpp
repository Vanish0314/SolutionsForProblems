/*
 * @Author: Vanish
 * @Date: 2024-10-21 20:31:03
 * @LastEditTime: 2024-10-21 21:34:59
 * Also View: http://vanishing.cc
 * Contract Me: qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] - '0' >0 && s[i]-'0' < 10)
            {
                int t = s.find_first_of('[',i);
                string numStr = s.substr(i,t-i);
                int num = stoi(numStr); // str 转 int
                i += t -i -1;
                
                int end = i;
                int pos = i + 1;
                stack<char> st;
                do
                {
                    if(s[pos] == '[')
                        st.push('[');
                    else if(s[pos] == ']')
                        st.pop();
                    pos++;
                }while(!st.empty());
                end = pos;

                string sub = s.substr(i+2,end - i - 3);
                for(int j = 0; j < num; j++)
                {
                    res += decodeString(sub);
                }
                i = end-1;
            }
            else
            {
                res += s[i];
            }
        }
        return res;

    }
};

// #include <iostream>
// int main()
// {
//     Solution s;
//     string str = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
//     cout<<s.decodeString(str)<<endl;
//     return 0;
// }
// @lc code=end


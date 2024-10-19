/*
 * @Author: Vanish
 * @Date: 2024-09-19 19:49:08
 * @LastEditTime: 2024-09-19 20:03:53
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    string keypad[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

private:
    vector<string> res = {};

private:
    void BackTrack(string digits, string oneSolution = "") 
    {
        if(digits.empty())
        {
            res.push_back(oneSolution);
            return;
        }

        for(char c : keypad[digits[0] - '0' -1])
        {
            oneSolution.push_back(c);
            BackTrack(digits.substr(1), oneSolution);
            oneSolution.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;

        BackTrack(digits);
        return res;
    }

};
// @lc code=end


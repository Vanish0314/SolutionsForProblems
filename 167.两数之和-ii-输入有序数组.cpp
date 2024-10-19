/*
 * @Author: Vanish
 * @Date: 2024-09-11 18:01:36
 * @LastEditTime: 2024-09-11 18:05:25
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIndex = 0;
        int *left = &numbers[0];
        int rightIndex = numbers.size()-1;
        int *right = &numbers[numbers.size()-1];

        while(*left + *right != target)
        {
            if(*left + *right < target)
            {
                left++;
                leftIndex++;
            }
            else
            {
                right--;
                rightIndex--;
            }
        }
        return vector<int>{leftIndex+1,rightIndex+1};
    }
};
// @lc code=end


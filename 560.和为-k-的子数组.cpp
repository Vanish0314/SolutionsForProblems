/*
 * @Author: Vanish
 * @Date: 2024-10-22 20:36:34
 * @LastEditTime: 2024-10-22 21:09:11
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start

#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1; // 初始化，表示当前和为0出现1次

        int count = 0;
        int current_sum = 0;

        for (int num : nums) {
            current_sum += num; // 更新当前和
            count += map[current_sum - k]; // 查找 current_sum - k 的出现次数
            map[current_sum]++; //更新当前和出现次数
        }

        return count;
    }
};
// @lc code=end


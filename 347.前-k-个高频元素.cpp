/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */


#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
// @lc code=start
class Solution {
public:

    static bool compare(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq(&compare);
        for(auto [num, freq] : freq)
        {
            if(pq.size() < k)
            {
                pq.emplace(freq, num);
            }
            else if(freq > pq.top().first)
            {
                pq.pop();
                pq.emplace(freq, num);
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end


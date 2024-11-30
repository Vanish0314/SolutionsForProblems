/*
 * @Author: Vanish
 * @Date: 2024-11-07 13:54:32
 * @LastEditTime: 2024-11-27 15:46:34
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// 判断有向图是否有环'
// TODO: 使用DFS超时,改用其他方法

#include <algorithm>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
  public:
    bool hasCircle(int node, multimap<int, int> &edges, vector<int> nodesThrough)
    {
        if (!edges.count(node))
            return false;
        if (find(nodesThrough.begin(), nodesThrough.end(), node) != nodesThrough.end())
        {
            return true;
        }

        // TIP:遍历multimap一个key的方法
        nodesThrough.emplace_back(node);
        auto range = edges.equal_range(node);
        for (auto it = range.first; it != range.second; it++)
        {
            if (hasCircle(it->second, edges, nodesThrough))
                return true;
        }
        nodesThrough.pop_back();
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        multimap<int, int> edges;

        for (auto edge : prerequisites)
        {
            edges.insert({edge[0], edge[1]});
        }

        vector<int> nodesThrough;
        for (int i = 0; i < numCourses; i++)
        {
            nodesThrough = {};
            if (hasCircle(i, edges, nodesThrough))
                return false;
        }

        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    int num = 5;
    vector<vector<int>> pre = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};

    s.canFinish(num, pre);
}

/*
 * @Author: Vanish
 * @Date: 2024-11-04 21:13:40
 * @LastEditTime: 2024-11-05 21:39:03
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;

        q.emplace(root);
        while(!q.empty())
        {
            vector<TreeNode*> level;
            while(!q.empty())
            {
                level.emplace_back(q.front());
                q.pop();
            }

            vector<int> level_val;
            for(auto node : level)
            {
                level_val.emplace_back(node->val);
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            res.emplace_back(level_val);
        }

        return res;
    }
};
// @lc code=end


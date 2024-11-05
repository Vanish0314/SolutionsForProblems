/*
 * @Author: Vanish
 * @Date: 2024-11-04 20:49:48
 * @LastEditTime: 2024-11-04 20:51:55
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include<algorithm>
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
    int depth(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        return 1 + max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};
// @lc code=end


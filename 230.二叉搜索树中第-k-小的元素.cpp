/*
 * @Author: Vanish
 * @Date: 2024-11-04 21:13:20
 * @LastEditTime: 2024-11-05 21:32:36
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */

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

#include <vector>

using namespace std;
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) 
    {
        if(!root) return;

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inorder(root,res);
        return res[k-1];
    }
};
// @lc code=end

